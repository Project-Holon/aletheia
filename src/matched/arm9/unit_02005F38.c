/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005F38
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_IsBgmPlaying, GFL_USE_CancelChangeDefaultFade, GFL_USE_BeginBgmChange, GFL_USE_CancelBgmChange,
 *           GFL_USE_FlushBgmChange
 *
 * symbols:
 *   sub_02005F38_State  0x020AA260  data
 *   GFL_USE_GetCurrentBgmId        0x020058D0  thumb
 *   GFL_USE_GetCurrentSndHandle        0x0200590C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm        0x02005D90  thumb
 *   GFL_USE_UpdateBgmChange        0x02005FF4  thumb
 *   GFL_USE_StopLoaderThread        0x02006368  thumb
 *   func_02072EE0       0x02072EE0  arm
 *   NNS_SndHandleSetSeqPriority       0x02072F34  arm
 *
 * The setup and teardown of the connection request block at 0x020AA260.
 * The range stops at 0x02005FF4 rather than running on to 0x02006148 for an
 * evidence reason: NNS_SndHandleSetSeqPriority is called from five places image wide and
 * four of them are inside GFL_USE_UpdateBgmChange, so the two files witness each
 * other's calls.
 *
 * GFL_USE_CancelChangeDefaultFade ends in a tail call to GFL_USE_CancelBgmChange, which is in this same
 * range, and it still goes through a literal pool and `bx r3` rather than a
 * branch: one section per function means the compiler cannot encode the
 * displacement even to its own neighbour, and the pool word is an ABS32 the
 * linker fills in.  Here that makes the site `local` and costs no image
 * evidence at all.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005F38State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    int unk2C;
    int unk30;
};

extern struct Sub02005F38State sub_02005F38_State;

extern u16  GFL_USE_GetCurrentBgmId(void);
extern u32 *GFL_USE_GetCurrentSndHandle(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u16 b);
extern void GFL_USE_UpdateBgmChange(void);
extern void GFL_USE_StopLoaderThread(void);
typedef signed int     s32;
extern s32 func_02072EE0(u32 tag);
typedef unsigned char  u8;
struct Obj;
extern void NNS_SndHandleSetSeqPriority(struct Obj *o, u8 v);

void GFL_USE_CancelBgmChange(void);

int GFL_USE_IsBgmPlaying(void)
{
    if (GFL_USE_GetCurrentBgmId() == 0) {
        return 0;
    }
    if (func_02072EE0(GFL_USE_GetCurrentBgmId()) != 0) {
        return 1;
    }
    return 0;
}

void GFL_USE_CancelChangeDefaultFade(void)
{
    sub_02005F38_State.unk2C = 60;
    sub_02005F38_State.unk30 = 60;
    GFL_USE_CancelBgmChange();
}

void GFL_USE_BeginBgmChange(u32 a, u16 b, int c, int d)
{
    sub_02005F38_State.unk26 = b;
    sub_02005F38_State.unk28 = a;
    sub_02005F38_State.unk2C = d;
    sub_02005F38_State.unk30 = c;
    sub_02005F38_State.unk24 = c;
    GFL_USE_StopLoaderThread();
    sub_02005F38_State.unk20 = 0;
    sub_02005F38_State.unk1C = 1;
}

void GFL_USE_CancelBgmChange(void)
{
    sub_02005F38_State.unk1C = 0;
    sub_02005F38_State.unk26 = 0xFFFF;
    sub_02005F38_State.unk28 = 0;
    sub_02005F38_State.unk24 = 0;
    NNS_SndHandleSetSeqPriority((struct Obj *)GFL_USE_GetCurrentSndHandle(), 0x7F);
    sub_02005F38_State.unk20 = 0;
    GFL_USE_StopLoaderThread();
}

void GFL_USE_FlushBgmChange(void)
{
    u32 id;

    if (sub_02005F38_State.unk1C != 1) {
        return;
    }
    id = GFL_USE_GetCurrentBgmId();
    if (id != sub_02005F38_State.unk28) {
        while (sub_02005F38_State.unk20 != 0) {
            GFL_USE_UpdateBgmChange();
        }
        GFL_USE_CancelChangeAndPlayBgm(sub_02005F38_State.unk28, sub_02005F38_State.unk26);
    }
    GFL_USE_CancelBgmChange();
}
