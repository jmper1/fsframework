/*-------------------------------------------------------------------------------------------------------*\
| Adium, Copyright (C) 2001-2005, Adam Iser  (adamiser@mac.com | http://www.adiumx.com)                   |
\---------------------------------------------------------------------------------------------------------/
 | This program is free software; you can redistribute it and/or modify it under the terms of the GNU
 | General Public License as published by the Free Software Foundation; either version 2 of the License,
 | or (at your option) any later version.
 |
 | This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 | the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 | Public License for more details.
 |
 | You should have received a copy of the GNU General Public License along with this program; if not,
 | write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 \------------------------------------------------------------------------------------------------------ */

/*
    Holds attributes that can be applied to a block of text
*/

#import "AITextAttributes.h"
#import "AIApplicationAdditions.h"
#import "AIFontManagerAdditions.h"

#define FONT_DEFAULT_NAME	@"Helvetica"

@interface AITextAttributes (PRIVATE)
- (id)initWithFontFamily:(NSString *)inFamilyName traits:(NSFontTraitMask)inTraits size:(int)inSize;
- (id)initWithDictionary:(NSDictionary *)inAttributes;
- (void)updateFont;
@end

@implementation AITextAttributes

//Creates a new instance of AITextAttributes
+ (id)textAttributesWithFontFamily:(NSString *)inFamilyName traits:(NSFontTraitMask)inTraits size:(int)inSize
{
    return [[[self alloc] initWithFontFamily:inFamilyName traits:inTraits size:inSize] autorelease];
}

+ (id)textAttributesWithDictionary:(NSDictionary *)inAttributes
{
	return [[[self alloc] initWithDictionary:inAttributes] autorelease];
}

//init
- (id)initWithFontFamily:(NSString *)inFamilyName traits:(NSFontTraitMask)inTraits size:(int)inSize
{
	if ((self = [self init])) {
		dictionary = [[NSMutableDictionary alloc] init];

		fontFamilyName = [inFamilyName retain];
		fontTraitsMask = inTraits;
		fontSize = inSize;
	}

	return self;
}

- (id)initWithDictionary:(NSDictionary *)inAttributes
{
	if ((self = [self init])) {
		dictionary = [inAttributes mutableCopy];

		NSFont	*font = [dictionary objectForKey:NSFontAttributeName];

		if (font) {
			fontFamilyName = [[font familyName] retain];
			fontTraitsMask = [[NSFontManager sharedFontManager] traitsOfFont:font];
			fontSize = [font pointSize];
		} else {
			fontFamilyName = [@"Helvetica" retain];
			fontTraitsMask = 0;
			fontSize = 12;
		}
	}

	return self;
}

- (id)init
{
	if ((self = [super init])) {
		dictionary = nil;
		fontFamilyName = nil;
		fontTraitsMask = 0;
		fontSize = 0;
	}

	return self;
}

//dealloc
- (void)dealloc
{
    [dictionary release];
    [fontFamilyName release];

    [super dealloc];
}

- (id)copyWithZone:(NSZone *)zone
{
	AITextAttributes	*newTextAttributes = [[AITextAttributes alloc] init];

	newTextAttributes->dictionary = [dictionary mutableCopy];
	newTextAttributes->fontFamilyName = [fontFamilyName retain];
	newTextAttributes->fontTraitsMask = fontTraitsMask;
	newTextAttributes->fontSize = fontSize;

	return newTextAttributes;
}

//Set the font family (name)
- (void)setFontFamily:(NSString *)inName
{
    if (fontFamilyName != inName) {
        [fontFamilyName release];
        fontFamilyName = [inName retain];

		[dictionary removeObjectForKey:NSFontAttributeName];
	}
}

- (NSString *)fontFamily
{
	return fontFamilyName;
}

//Set the font size
- (void)setFontSize:(int)inSize
{
	if (fontSize != inSize) {
		fontSize = inSize;
		
		[dictionary removeObjectForKey:NSFontAttributeName];
	}
}

//Set the text foreground color
- (void)setTextColor:(NSColor *)inColor
{
	if (inColor) {
		[dictionary setObject:inColor forKey:NSForegroundColorAttributeName];
	} else {
		[dictionary removeObjectForKey:NSForegroundColorAttributeName];
	}
}

//Sub-backround color (drawn just behind the text)
- (void)setTextBackgroundColor:(NSColor *)inColor
{
	if (inColor) {
		[dictionary setObject:inColor forKey:NSBackgroundColorAttributeName];
	} else {
		[dictionary removeObjectForKey:NSBackgroundColorAttributeName];
	}
}

//Set the background color
- (void)setBackgroundColor:(NSColor *)inColor
{
    [dictionary setObject:inColor forKey:AIBodyColorAttributeName];
}

//Enable a masked trait (bold, italic)
- (void)enableTrait:(NSFontTraitMask)inTrait
{
    fontTraitsMask |= inTrait;
	[dictionary removeObjectForKey:NSFontAttributeName];
}

//Disable a masked trait (bold, italic)
- (void)disableTrait:(NSFontTraitMask)inTrait
{
    if (fontTraitsMask && inTrait) {
        fontTraitsMask ^= inTrait;
    }
    
	[dictionary removeObjectForKey:NSFontAttributeName];
}

//Enable/Disable underlining
- (void)setUnderline:(BOOL)inUnderline
{
    if (inUnderline) {
        [dictionary setObject:[NSNumber numberWithBool:inUnderline] forKey:NSUnderlineStyleAttributeName];
    } else {
        [dictionary removeObjectForKey:NSUnderlineStyleAttributeName];
    }
}

// Enable or disable strikethrough
- (void)setStrikethrough:(BOOL)inStrikethrough{
	if (inStrikethrough) {
		[dictionary setObject:[NSNumber numberWithBool:inStrikethrough] forKey:NSStrikethroughStyleAttributeName];
	} else {
		[dictionary removeObjectForKey:NSStrikethroughStyleAttributeName];
	}
} 

// Enable or disable subscript
- (void)setSubscript:(BOOL)inSubscript{
	if (inSubscript) {
		[dictionary setObject:[NSNumber numberWithFloat:(fontSize / -2.0f)] forKey:NSBaselineOffsetAttributeName];
		[self setFontSize:(fontSize - 2)];
		
	} else {
		[dictionary removeObjectForKey:NSBaselineOffsetAttributeName];
		[self setFontSize:(fontSize + 2)];
	}
}

// Enable or disable superscript
- (void)setSuperscript:(BOOL)inSuperscript{
	if (inSuperscript) {
		[dictionary setObject:[NSNumber numberWithFloat:(fontSize / 2.0f)] forKey:NSBaselineOffsetAttributeName];
		[self setFontSize:(fontSize - 2)];

	} else {
		[dictionary removeObjectForKey:NSBaselineOffsetAttributeName];
		[self setFontSize:(fontSize + 2)];
	}
}

- (void)setLinkURL:(NSURL *)inURL
{
    if (inURL) {
        [dictionary setObject:inURL forKey:NSLinkAttributeName];
    } else {
        [dictionary removeObjectForKey:NSLinkAttributeName];
    }
}

- (void)setLanguageValue:(id)languageValue
{
	if (languageValue) {
		[dictionary setObject:languageValue forKey:@"LanguageValue"];
	} else {
		[dictionary removeObjectForKey:@"LanguageValue"];		
	}
}

- (id)languageValue
{
	return [dictionary objectForKey:@"LanguageValue"];
}

//Returns a dictinary of attributes
- (NSDictionary *)dictionary
{
	//If the dictionary doesn't specify a font, it means our font has changed since the last call here. Update now.
	if (![dictionary objectForKey:NSFontAttributeName]) [self updateFont];

    return dictionary;
}

- (void)resetFontAttributes
{
	[fontFamilyName release]; fontFamilyName = nil;
	fontSize = 0;
	[dictionary removeObjectForKey:NSForegroundColorAttributeName];
	[dictionary removeObjectForKey:NSBackgroundColorAttributeName];
	[dictionary removeObjectForKey:@"LanguageValue"];
}

//Updates the cached font
- (void)updateFont
{
    NSFont	*font = nil;

    //Ensure font size isn't 0
    if (!fontSize) fontSize = 12;

    //Create the font
    if (fontFamilyName) {
		font = [[NSFontManager sharedFontManager] fontWithFamilyInsensitively:fontFamilyName 
																	   traits:fontTraitsMask
																	   weight:5
																		 size:fontSize];
    }
    
    //If no name was specified or the font is not available, use the default font
    if (!font) {
        font = [[NSFontManager sharedFontManager] fontWithFamily:FONT_DEFAULT_NAME
														  traits:fontTraitsMask
														  weight:5
															size:fontSize];
    }

    if (font) { //Just to be safe, incase the default font was unavailable for some reason
        [dictionary setObject:font forKey:NSFontAttributeName];
    }
}

- (void)setWritingDirection:(NSWritingDirection)inDirection
{
	NSParagraphStyle			*paragraphStyle;
	NSMutableParagraphStyle		*newParagraphStyle;
	
	if (!(paragraphStyle = [dictionary objectForKey:NSParagraphStyleAttributeName])) {
		paragraphStyle = [NSParagraphStyle defaultParagraphStyle];
	}
	
	newParagraphStyle = [paragraphStyle mutableCopy];
	[newParagraphStyle setBaseWritingDirection:inDirection];
	[dictionary setObject:newParagraphStyle forKey:NSParagraphStyleAttributeName];
}

@end