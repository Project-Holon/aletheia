#ifndef OV009_DWC_AUTH_TYPES_H
#define OV009_DWC_AUTH_TYPES_H
/*
 * Shared DWC authentication types for ov009 (dwc_auth, dwc_auth_interface,
 * and the other objects that touch the auth state blocks). One definition
 * per object; offsets checked against every view the parts had.
 *
 * Addresses: gDwcAuthState DWCAuthState (0x1c), gDwcAuthParam DWCAuthParam (0x48),
 * gDwcAuthResultBuf the 0x1c50-byte result work buffer.
 */

/* Auth state block read by the DWCi_Auth_Is and DWCi_Auth_Get accessors. */
typedef struct DWCAuthState {
    int finished;                       /* 0x00 */
    int returnCode;                     /* 0x04 */
    int state;                          /* 0x08, 1 once authentication succeeded */
    unsigned long long userid;          /* 0x0c */
    unsigned long long tick;            /* 0x14 */
} DWCAuthState;

/* Parameter block copied in by DWCi_Auth_StartAuthentication. */
#include "../sdk_dwc.h"

/* The 0x1c4-byte result the auth thread fills in from the NAS response.
 * Field sizes come from the header labels the parser reads (token, locator,
 * challenge, datetime, Set-Cookie); see dwc_auth.c DWCi_Auth_FillResult. */
#endif
