#ifndef ALETHEIA_OV115_TYPES_H
#define ALETHEIA_OV115_TYPES_H

/*
 * Types of the Wi-Fi login overlay (ov115). wifilogin_disp.c threads the work
 * object through its step callbacks; the state object hangs off the work
 * object at +0x40 and carries the session identifiers and error flags.
 */

/* Session state of one Wi-Fi login attempt. */
struct WifiloginState {
    unsigned char pad00[4];
    unsigned int touchEnabled;  /* 0x04: non-zero enables the touch-panel cancel check */
    unsigned int reconnect;     /* 0x08: non-zero restarts with the default timeout */
    unsigned int dialogId;      /* 0x0C: message/dialog id (10, 36 or 44) */
    unsigned int waiting;       /* 0x10: non-zero while waiting on the server */
    unsigned int netMode;       /* 0x14: current network mode (2 handled specially) */
    unsigned int cancelBgm;     /* 0x18: zero cancels the change and plays the BGM */
    unsigned int aidMismatch;   /* 0x1C: set when this console is not the current aid */
};

/* Per-frame state-machine context threaded through the login steps. */
struct WifiloginWork {
    unsigned int stateHandler;  /* 0x00: current step callback */
    unsigned char pad04[0x3C];
    unsigned int state;         /* 0x40: pointer to the WifiloginState */
};

#endif
