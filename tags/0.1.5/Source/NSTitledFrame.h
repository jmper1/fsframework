/* 
 * The Fadingred.org Shared Framework (FSFramework) is the legal property of its developers, whose names
 * are listed in the copyright file included with this source distribution.
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/* This code is taken from Sean Patrick O'Brien's iLife Controls
 * and has been minimally modified.  It is published under an MIT
 * license, and that license holds for this file. */

/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "NSFrameView.h"

@class NSDocumentDragButton;

@interface NSTitledFrame : NSFrameView
{
    int resizeFlags;
    NSDocumentDragButton *fileButton;
    struct _NSSize titleCellSize;
}

+ (void)initialize;
+ (float)_windowBorderThickness:(unsigned int)fp8;
+ (float)_minXWindowBorderWidth:(unsigned int)fp8;
+ (float)_maxXWindowBorderWidth:(unsigned int)fp8;
+ (float)_minYWindowBorderHeight:(unsigned int)fp8;
+ (BOOL)_resizeFromEdge;
+ (struct _NSRect)frameRectForContentRect:(struct _NSRect)fp8 styleMask:(unsigned int)fp24;
+ (struct _NSRect)contentRectForFrameRect:(struct _NSRect)fp8 styleMask:(unsigned int)fp24;
+ (struct _NSSize)minFrameSizeForMinContentSize:(struct _NSSize)fp8 styleMask:(unsigned int)fp16;
+ (struct _NSSize)minContentSizeForMinFrameSize:(struct _NSSize)fp8 styleMask:(unsigned int)fp16;
+ (float)minFrameWidthWithTitle:(id)fp8 styleMask:(unsigned int)fp12;
+ (struct _NSSize)_titleCellSizeForTitle:(id)fp8 styleMask:(unsigned int)fp12;
+ (float)_titleCellHeight:(unsigned int)fp8;
+ (float)_windowTitlebarTitleMinHeight:(unsigned int)fp8;
+ (float)_titlebarHeight:(unsigned int)fp8;
+ (struct _NSSize)sizeOfTitlebarButtons:(unsigned int)fp8;
+ (float)windowTitlebarLinesSpacingWidth:(unsigned int)fp8;
+ (float)windowTitlebarTitleLinesSpacingWidth:(unsigned int)fp8;
+ (float)_contentToFrameMinXWidth:(unsigned int)fp8;
+ (float)_contentToFrameMaxXWidth:(unsigned int)fp8;
+ (float)_contentToFrameMinYHeight:(unsigned int)fp8;
+ (float)_contentToFrameMaxYHeight:(unsigned int)fp8;
- (id)initWithFrame:(struct _NSRect)fp8 styleMask:(unsigned int)fp24 owner:(id)fp28;
- (void)dealloc;
- (void)setIsClosable:(BOOL)fp8;
- (void)setIsResizable:(BOOL)fp8;
- (void)_resetTitleFont;
- (void)_setUtilityWindow:(BOOL)fp8;
- (BOOL)isOpaque;
- (BOOL)worksWhenModal;
- (void)propagateFrameDirtyRects:(struct _NSRect)fp8;
- (void)_showDrawRect:(struct _NSRect)fp8;
- (id)frameHighlightColor;
- (id)frameShadowColor;
- (void)setFrameOrigin:(struct _NSPoint)fp8;
- (void)tileAndSetWindowShape:(BOOL)fp8;
- (void)tile;
- (void)_tileTitlebarAndRedisplay:(BOOL)fp8;
- (void)setTitle:(id)fp8;
- (BOOL)_shouldRepresentFilename;
- (void)setRepresentedFilename:(id)fp8;
- (void)_drawTitleStringIn:(struct _NSRect)fp8 withColor:(id)fp24;
- (id)titleFont;
- (id)titleButtonOfClass:(Class)fp8;
- (id)initTitleButton:(id)fp8;
- (id)newCloseButton;
- (id)newZoomButton;
- (id)newMiniaturizeButton;
- (id)newFileButton;
- (id)fileButton;
- (void)_removeButtons;
- (void)_updateButtons;
- (BOOL)_eventInTitlebar:(id)fp8;
- (BOOL)acceptsFirstMouse:(id)fp8;
- (void)mouseDown:(id)fp8;
- (void)mouseUp:(id)fp8;
- (void)rightMouseDown:(id)fp8;
- (void)rightMouseUp:(id)fp8;
- (int)resizeEdgeForEvent:(id)fp8;
- (struct _NSSize)_resizeDeltaFromPoint:(struct _NSPoint)fp8 toEvent:(id)fp16;
- (struct _NSRect)_validFrameForResizeFrame:(struct _NSRect)fp8 fromResizeEdge:(int)fp24;
- (struct _NSRect)frame:(struct _NSRect)fp8 resizedFromEdge:(int)fp24 withDelta:(struct _NSSize)fp28;
- (BOOL)constrainResizeEdge:(int *)fp8 withDelta:(struct _NSSize)fp12 elapsedTime:(float)fp20;
- (void)resizeWithEvent:(id)fp8;
- (int)resizeFlags;
- (void)resetCursorRects;
- (void)setDocumentEdited:(BOOL)fp8;
- (struct _NSSize)miniaturizedSize;
- (struct _NSSize)minFrameSize;
- (float)_windowBorderThickness;
- (float)_windowTitlebarXResizeBorderThickness;
- (float)_windowTitlebarYResizeBorderThickness;
- (float)_windowResizeBorderThickness;
- (float)_minXWindowBorderWidth;
- (float)_maxXWindowBorderWidth;
- (float)_minYWindowBorderHeight;
- (id)_customTitleCell;
- (void)_invalidateTitleCellSize;
- (void)_invalidateTitleCellWidth;
- (float)_titleCellHeight;
- (struct _NSSize)_titleCellSize;
- (float)_titlebarHeight;
- (struct _NSRect)titlebarRect;
- (struct _NSRect)_maxTitlebarTitleRect;
- (struct _NSRect)_titlebarTitleRect;
- (float)_windowTitlebarTitleMinHeight;
- (struct _NSRect)dragRectForFrameRect:(struct _NSRect)fp8;
- (struct _NSSize)sizeOfTitlebarButtons;
- (struct _NSSize)_sizeOfTitlebarFileButton;
- (float)_windowTitlebarButtonSpacingWidth;
- (float)_minXTitlebarButtonsWidth;
- (float)_maxXTitlebarButtonsWidth;
- (int)_numberOfTitlebarLines;
- (float)windowTitlebarLinesSpacingWidth;
- (float)windowTitlebarTitleLinesSpacingWidth;
- (float)_minLinesWidthWithSpace;
- (struct _NSRect)_minXTitlebarLinesRectWithTitleCellRect:(struct _NSRect)fp8;
- (struct _NSRect)_maxXTitlebarLinesRectWithTitleCellRect:(struct _NSRect)fp8;
- (float)_minXTitlebarDecorationMinWidth;
- (float)_maxXTitlebarDecorationMinWidth;
- (struct _NSPoint)_closeButtonOrigin;
- (struct _NSPoint)_zoomButtonOrigin;
- (struct _NSPoint)_collapseButtonOrigin;
- (struct _NSPoint)_fileButtonOrigin;
- (float)_maxYTitlebarDragHeight;
- (float)_minXTitlebarDragWidth;
- (float)_maxXTitlebarDragWidth;
- (float)_contentToFrameMinXWidth;
- (float)_contentToFrameMaxXWidth;
- (float)_contentToFrameMinYHeight;
- (float)_contentToFrameMaxYHeight;
- (struct _NSRect)contentRect;
- (float)_windowResizeCornerThickness;
- (struct _NSRect)_minYResizeRect;
- (struct _NSRect)_minYminXResizeRect;
- (struct _NSRect)_minYmaxXResizeRect;
- (struct _NSRect)_minXResizeRect;
- (struct _NSRect)_minXminYResizeRect;
- (struct _NSRect)_minXmaxYResizeRect;
- (struct _NSRect)_maxYResizeRect;
- (struct _NSRect)_maxYminXResizeRect;
- (struct _NSRect)_maxYmaxXResizeRect;
- (struct _NSRect)_maxXResizeRect;
- (struct _NSRect)_maxXminYResizeRect;
- (struct _NSRect)_maxXmaxYResizeRect;
- (struct _NSRect)_minXTitlebarResizeRect;
- (struct _NSRect)_maxXTitlebarResizeRect;
- (struct _NSRect)_minXBorderRect;
- (struct _NSRect)_maxXBorderRect;
- (struct _NSRect)_maxYBorderRect;
- (struct _NSRect)_minYBorderRect;

@end

