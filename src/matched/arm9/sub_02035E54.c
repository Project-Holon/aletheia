/*
 * function: TOUCHPANEL_ClearFrameRateWork
 * address:  0x02035E54
 * packet:   pkt_02035C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetWork  0x02035750  arm
 *
 * Zeroes the eight-halfword counter block at +0x64 of the record
 * TOUCHPANEL_GetWork resolves its argument to.  One of the two follow-up passes
 * that src/pending/UI_ChangeFrameRate.c runs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_ClearFrameRateWork.c \
 *       --func TOUCHPANEL_ClearFrameRateWork --addr 0x02035E54 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Sio {
    u8 pad_00[0x64];
    u16 unk64;
    u16 unk66;
    u16 unk68;
    u16 unk6a;
    u16 unk6c;
    u16 unk6e;
    u16 unk70;
    u16 unk72;
};

extern int TOUCHPANEL_GetWork(void);

void TOUCHPANEL_ClearFrameRateWork(struct Sio *p)
{
    struct Sio *sio = (struct Sio *)TOUCHPANEL_GetWork();

    sio->unk64 = 0;
    sio->unk66 = 0;
    sio->unk68 = 0;
    sio->unk6a = 0;
    sio->unk6c = 0;
    sio->unk6e = 0;
    sio->unk70 = 0;
    sio->unk72 = 0;
}
