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

#import "AIFontManagerAdditions.h"

@implementation NSFontManager (AIFontManagerAdditions)

- (NSFont *)fontWithFamilyInsensitively:(NSString *)name traits:(NSFontTraitMask)fontTraitMask weight:(int)weight size:(float)size
{
	NSFont			*theFont = nil;
	NSFontManager	*fontManager = [NSFontManager sharedFontManager];

	@try
	{
		theFont = [fontManager fontWithFamily:name traits:fontTraitMask weight:weight size:size];
	}
	@catch (NSException *localException)
	{
		theFont = nil;
	}

	if (!theFont) {
		NSEnumerator	*fontEnum;
		NSString		*thisName;

		fontEnum = [[fontManager availableFontFamilies] objectEnumerator];
		while ((thisName = [fontEnum nextObject])) {
			if ([thisName caseInsensitiveCompare:name] == NSOrderedSame) {
				@try
				{
					theFont = [fontManager fontWithFamily:thisName traits:fontTraitMask weight:weight size:size];				
					break;
				}
				@catch (NSException *localException)
				{
					theFont = nil;
				}
			}
		}
	}

	return theFont;
}

@end
