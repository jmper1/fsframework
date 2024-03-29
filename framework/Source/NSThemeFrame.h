/* 
 * The FadingRed Shared Framework (FSFramework) is the legal property of its developers, whose names
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
 * and has been minimally modified */

#import "NSTitledFrame.h"

@class NSButton, NSImage, NSString;

@interface NSThemeFrame : NSTitledFrame
{
    NSButton *toolbarButton;
    int toolbarVisibleStatus;
    NSImage *showToolbarTransitionImage;
    struct _NSSize showToolbarPreWindowSize;
    NSButton *modeButton;
    int leftGroupTrackingTagNum;
    int rightGroupTrackingTagNum;
    BOOL mouseInsideLeftGroup;
    BOOL mouseInsideRightGroup;
    int widgetState;
    NSString *displayName;
}

+ (void)initialize;
+ (void)drawBevel:(struct _NSRect)fp8 inFrame:(struct _NSRect)fp24 topCornerRounded:(BOOL)fp40;
+ (float)_windowBorderThickness:(unsigned int)fp8;
+ (float)_minXWindowBorderWidth:(unsigned int)fp8;
+ (float)_maxXWindowBorderWidth:(unsigned int)fp8;
+ (float)_minYWindowBorderHeight:(unsigned int)fp8;
+ (float)_windowTitlebarButtonSpacingWidth:(unsigned int)fp8;
+ (float)_windowFileButtonSpacingWidth:(unsigned int)fp8;
+ (float)_minXTitlebarWidgetInset:(unsigned int)fp8;
+ (float)_maxXTitlebarWidgetInset:(unsigned int)fp8;
+ (float)minFrameWidthWithTitle:(id)fp8 styleMask:(unsigned int)fp12;
+ (float)_windowSideTitlebarTitleMinWidth:(unsigned int)fp8;
+ (float)_windowTitlebarTitleMinHeight:(unsigned int)fp8;
+ (float)_sideTitlebarWidth:(unsigned int)fp8;
+ (float)_titlebarHeight:(unsigned int)fp8;
+ (float)_resizeHeight:(unsigned int)fp8;
+ (BOOL)_resizeFromEdge;
+ (struct _NSSize)sizeOfTitlebarButtons:(unsigned int)fp8;
+ (float)_contentToFrameMinXWidth:(unsigned int)fp8;
+ (float)_contentToFrameMaxXWidth:(unsigned int)fp8;
+ (float)_contentToFrameMinYHeight:(unsigned int)fp8;
+ (float)_contentToFrameMaxYHeight:(unsigned int)fp8;
+ (unsigned int)_validateStyleMask:(unsigned int)fp8;
- (struct _NSSize)_topCornerSize;
- (struct _NSSize)_bottomCornerSize;
- (void *)_createWindowOpaqueShape;
- (void)shapeWindow;
- (void)_recursiveDisplayRectIfNeededIgnoringOpacity:(struct _NSRect)fp8 isVisibleRect:(BOOL)fp24 rectIsVisibleRectForView:(id)fp28 topView:(BOOL)fp32;
- (void *)_regionForOpaqueDescendants:(struct _NSRect)fp8 forMove:(BOOL)fp24;
- (void)_drawFrameInterior:(struct _NSRect *)fp8 clip:(struct _NSRect)fp12;
- (void)_setTextShadow:(BOOL)fp8;
- (BOOL)_isOnePieceTitleAndToolbar;
- (void)_drawUnifiedToolbarBackgroundInRect:(struct _NSRect)fp8 withState:(int)fp24;
- (void)_drawUnifiedToolbar:(int)fp8;
- (void)_drawTitleBar:(struct _NSRect)fp8;
- (void)_drawResizeIndicators:(struct _NSRect)fp8;
- (void)_drawFrameRects:(struct _NSRect)fp8;
- (void)drawFrame:(struct _NSRect)fp8;
- (id)contentFill;
- (void)viewDidEndLiveResize;
- (float)contentAlpha;
- (void)setThemeFrameWidgetState:(int)fp8;
- (BOOL)constrainResizeEdge:(int *)fp8 withDelta:(struct _NSSize)fp12 elapsedTime:(float)fp20;
- (void)addFileButton:(id)fp8;
- (void)_updateButtons;
- (void)_updateButtonState;
- (id)newCloseButton;
- (id)newZoomButton;
- (id)newMiniaturizeButton;
- (id)newToolbarButton;
- (id)newFileButton;
- (void)_resetTitleBarButtons;
- (void)setDocumentEdited:(BOOL)fp8;
- (id)toolbarButton;
- (id)modeButton;
- (id)initWithFrame:(struct _NSRect)fp8 styleMask:(unsigned int)fp24 owner:(id)fp28;
- (void)setIsResizable:(BOOL)fp8;
- (void)dealloc;
- (void)finalize;
- (BOOL)preservesContentDuringLiveResize;
- (void)setFrameSize:(struct _NSSize)fp8;
- (BOOL)_canHaveToolbar;
- (BOOL)_toolbarIsInTransition;
- (BOOL)_toolbarIsShown;
- (BOOL)_toolbarIsHidden;
- (id)_toolbarView;
- (id)_toolbar;
- (float)_distanceFromToolbarBaseToTitlebar;
- (unsigned int)_shadowFlags;
- (struct _NSRect)frameRectForContentRect:(struct _NSRect)fp8 styleMask:(unsigned int)fp24;
- (struct _NSRect)contentRectForFrameRect:(struct _NSRect)fp8 styleMask:(unsigned int)fp24;
- (struct _NSSize)minFrameSizeForMinContentSize:(struct _NSSize)fp8 styleMask:(unsigned int)fp16;
- (struct _NSRect)contentRect;
- (struct _NSRect)_contentRectExcludingToolbar;
- (struct _NSRect)_contentRectIncludingToolbarAtHome;
- (void)_setToolbarShowHideResizeWeightingOptimizationOn:(BOOL)fp8;
- (BOOL)_usingToolbarShowHideWeightingOptimization;
- (void)handleSetFrameCommonRedisplay;
- (void)_startLiveResizeAsTopLevel;
- (void)_endLiveResizeAsTopLevel;
- (void)_growContentReshapeContentAndToolbarView:(int)fp8 animate:(BOOL)fp12;
- (BOOL)_growWindowReshapeContentAndToolbarView:(int)fp8 animate:(BOOL)fp12;
- (void)_reshapeContentAndToolbarView:(int)fp8 resizeWindow:(BOOL)fp12 animate:(BOOL)fp16;
- (void)_toolbarFrameSizeChanged:(id)fp8 oldSize:(struct _NSSize)fp12;
- (void)_syncToolbarPosition;
- (void)_showHideToolbar:(int)fp8 resizeWindow:(BOOL)fp12 animate:(BOOL)fp16;
- (void)_showToolbarWithAnimation:(BOOL)fp8;
- (void)_hideToolbarWithAnimation:(BOOL)fp8;
- (void)_drawToolbarTransitionIfNecessary;
- (void)drawRect:(struct _NSRect)fp8;
- (void)resetCursorRects;
- (BOOL)shouldBeTreatedAsInkEvent:(id)fp8;
- (BOOL)_shouldBeTreatedAsInkEventInInactiveWindow:(id)fp8;
- (id)hitTest:(struct _NSPoint)fp8;
- (struct _NSRect)_leftGroupRect;
- (struct _NSRect)_rightGroupRect;
- (void)_updateWidgets;
- (void)_updateMouseTracking;
- (void)mouseEntered:(id)fp8;
- (void)mouseExited:(id)fp8;
- (void)_setMouseEnteredGroup:(BOOL)fp8 entered:(BOOL)fp12;
- (BOOL)_mouseInGroup:(id)fp8;
- (struct _NSSize)miniaturizedSize;
- (float)_minXTitlebarDecorationMinWidth;
- (float)_maxXTitlebarDecorationMinWidth;
- (struct _NSSize)minFrameSize;
- (float)_windowBorderThickness;
- (float)_windowTitlebarXResizeBorderThickness;
- (float)_windowTitlebarYResizeBorderThickness;
- (float)_windowResizeBorderThickness;
- (float)_minXWindowBorderWidth;
- (float)_maxXWindowBorderWidth;
- (float)_minYWindowBorderHeight;
- (float)_maxYWindowBorderHeight;
- (float)_minYTitlebarButtonsOffset;
- (float)_minYTitlebarTitleOffset;
- (float)_sideTitlebarWidth;
- (float)_titlebarHeight;
- (struct _NSRect)_defaultTitlebarTitleRect;
- (struct _NSRect)_titlebarTitleRect;
- (struct _NSRect)titlebarRect;
- (float)_windowTitlebarTitleMinHeight;
- (struct _NSSize)_sizeOfTitlebarFileButton;
- (struct _NSSize)sizeOfTitlebarToolbarButton;
- (float)_windowTitlebarButtonSpacingWidth;
- (float)_windowFileButtonSpacingWidth;
- (float)_minXTitlebarWidgetInset;
- (float)_maxXTitlebarWidgetInset;
- (float)_minXTitlebarButtonsWidth;
- (float)_maxXTitlebarButtonsWidth;
- (struct _NSPoint)_closeButtonOrigin;
- (struct _NSPoint)_zoomButtonOrigin;
- (struct _NSPoint)_collapseButtonOrigin;
- (struct _NSPoint)_toolbarButtonOrigin;
- (struct _NSPoint)_fileButtonOrigin;
- (void)_tileTitlebarAndRedisplay:(BOOL)fp8;
- (struct _NSRect)_commandPopupRect;
- (void)_resetDragMargins;
- (float)_maxYTitlebarDragHeight;
- (float)_minXTitlebarDragWidth;
- (float)_maxXTitlebarDragWidth;
- (float)_contentToFrameMinXWidth;
- (float)_contentToFrameMaxXWidth;
- (float)_contentToFrameMinYHeight;
- (float)_contentToFrameMaxYHeight;
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
- (void)_setUtilityWindow:(BOOL)fp8;
- (BOOL)_isUtility;
- (float)_sheetHeightAdjustment;
- (void)_setSheet:(BOOL)fp8;
- (BOOL)_isSheet;
- (BOOL)_isResizable;
- (BOOL)_isClosable;
- (BOOL)_isMiniaturizable;
- (BOOL)_hasToolbar;
- (struct _NSRect)_growBoxRect;
- (void)_drawGrowBoxWithClip:(struct _NSRect)fp8;
- (BOOL)_inactiveButtonsNeedMask;
- (void)mouseDown:(id)fp8;
- (id)_displayName;
- (void)_setDisplayName:(id)fp8;

@end

