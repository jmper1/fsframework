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

@interface FSAlertExtensions : NSObject {
	NSWindow *_window;
	NSTextField *_title;
	NSTextField *_msg;
	NSButton *_defaultButton;
	NSButton *_otherButton;
	NSButton *_check;
	NSImageView *_image;
	BOOL *_checkValue;
	NSTextView *_detailsText;
	NSButton *_detailsButton;
	NSButton *_detailsButtonText;
	BOOL *_detailsState;

	BOOL _sendCheckValue;
	BOOL _sendDetailsState;
	SEL _didEndSelector;
	SEL _didDismissSelector;
	id _modalDelegate;
	void *_contextInfo;
}

int RunAlertPanel(
		NSString *title,
		NSString *msg,
		NSString *defaultButton,
		NSString *otherButton);
/*
	only advantageous over NSRunAlertPanel if calls to other RunAlertPanel functions in application
*/

int RunAlertPanelWithCheckbox(
		NSString *title,
		NSString *msg,
		NSString *defaultButton,
		NSString *otherButton,
		NSString *checkboxString,
		BOOL *checkboxState);
/*
	note checkboxState is a pointer so you can know the state of the checkbox after the call
*/

int RunAlertPanelWithDetails(
		NSString *title,
		NSString *msg,
		NSString *defaultButton,
		NSString *otherButton,
		NSString *detailsString,
		NSString *detailsButtonTitle,
		BOOL *detailsState);
/*
	note detailsState is a pointer so you can know the state of the details dropdown after the call
*/

int RunAlertPanelWithCheckboxAndDetails(
		NSString *title,
		NSString *msg,
		NSString *defaultButton,
		NSString *otherButton,
		NSString *checkboxString,
		BOOL *checkboxState,
		NSString *detailsString,
		NSString *detailsButtonTitle,
		BOOL *detailsState);
/*
	note checkboxState and detailsState are pointers so you can know the states of the checkbox and the details dropdown after the call
*/

void BeginAlertSheet(
		NSString *title,
		NSString *defaultButton,
		NSString *otherButton,
		NSWindow *docWindow,
		id modalDelegate,
		SEL didEndSelector,
		SEL didDismissSelector,
		void *contextInfo,
		NSString *msg);
/*
	didEndSelector and didDismiss selectors take the form:
	  - (void)sheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo
	  - (void)sheetDidDismiss:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo
*/

void BeginAlertSheetWithCheckbox(
		NSString *title,
		NSString *defaultButton,
		NSString *otherButton,
		NSWindow *docWindow,
		id modalDelegate,
		SEL didEndSelector,
		SEL didDismissSelector,
		void *contextInfo,
		NSString *msg,
		NSString *checkboxString,
		BOOL checkboxState);
/*
	didEndSelector and didDismiss selectors take the form:
	  - (void)sheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode checkboxState:(BOOL)checkboxState contextInfo:(void *)contextInfo
	  - (void)sheetDidDismiss:(NSWindow *)sheet returnCode:(int)returnCode checkboxState:(BOOL)checkboxState contextInfo:(void *)contextInfo
*/
		
void BeginAlertSheetWithDetails(
		NSString *title,
		NSString *defaultButton,
		NSString *otherButton,
		NSWindow *docWindow,
		id modalDelegate,
		SEL didEndSelector,
		SEL didDismissSelector,
		void *contextInfo,
		NSString *msg,
		NSString *detailsString,
		NSString *detailsButtonTitle,
		BOOL detailsState);
/*
	didEndSelector and didDismiss selectors take the form:
	  - (void)sheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode detailsState:(BOOL)detailsState contextInfo:(void *)contextInfo
	  - (void)sheetDidDismiss:(NSWindow *)sheet returnCode:(int)returnCode detailsState:(BOOL)detailsState contextInfo:(void *)contextInfo
*/

void BeginAlertSheetWithCheckboxAndDetails(
		NSString *title,
		NSString *defaultButton,
		NSString *otherButton,
		NSWindow *docWindow,
		id modalDelegate,
		SEL didEndSelector,
		SEL didDismissSelector,
		void *contextInfo,
		NSString *msg,
		NSString *checkboxString,
		BOOL checkboxState,
		NSString *detailsString,
		NSString *detailsButtonTitle,
		BOOL detailsState);
/*
	didEndSelector and didDismiss selectors take the form:
	  - (void)sheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode checkboxState:(BOOL)checkboxState detailsState:(BOOL)detailsState contextInfo:(void *)contextInfo
	  - (void)sheetDidDismiss:(NSWindow *)sheet returnCode:(int)returnCode checkboxState:(BOOL)checkboxState detailsState:(BOOL)detailsState contextInfo:(void *)contextInfo
	  
	either selector taking four arguments instead of five is fine, this option is available for convience, and is not alterable.
	the selectors then take the same form as those for BeginAlertSheetWithCheckbox:
	  - (void)sheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode checkboxState:(BOOL)checkboxState contextInfo:(void *)contextInfo
	  - (void)sheetDidDismiss:(NSWindow *)sheet returnCode:(int)returnCode checkboxState:(BOOL)checkboxState contextInfo:(void *)contextInfo
*/

@end