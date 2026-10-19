#ifndef FIELD_SOUND_SYSTEM_SHARED_TYPES_H
#define FIELD_SOUND_SYSTEM_SHARED_TYPES_H

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Fader;

/* The ringtone state machine object (12 bytes), created by the field sound system. */
typedef struct Ringtone {
    u32 state;                      /* 0x00 RingtoneState: bit 0 = ringing, bit 1 = asleep */
    u16 ringFramesLeft;             /* 0x04 */
    u16 reserved;                   /* 0x06 */
    struct Fader *volumeFader;      /* 0x08 */
} Ringtone;

#endif
