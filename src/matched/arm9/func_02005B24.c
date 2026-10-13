/*
 * function: GFL_USE_InitSound
 * address:  0x02005B24
 * packet:   pkt_02005B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02005B6C - the 8-byte ARM `ldr pc, [pc, #-4]` stub at 0x02005B6C
 *           and its pointer word 0x02704364, which lies outside every region
 *           of layout/layout.json, so `veneer_at()`'s `names_known_code()`
 *           refuses it and the `veneer` class cannot attest the call.
 *
 * symbols:
 *   _SndHeapBuf   0x020AA9B4  data
 *   _SndState   0x020AA260  data
 *   _SndArcPath   0x020A7010  data
 *   _SndArc   0x020AA2BC  data
 *   func_020726D0  0x020726D0  arm
 *   NNS_SndHeapCreate  0x020746E8  arm
 *   NNS_SndArcInit  0x02073FB8  arm
 *   GFL_USE_ResetSound  0x02005B74  thumb
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02005B6C  0x02005B6C  arm
 *
 * Network bring-up: take a block out of the static buffer at 0x020AA9B4
 * (0x95AD0 bytes, a pool word and not a `movs`-able constant), publish the
 * handle at +0x10 of the connection-slot global and hand the pair to the
 * handler installer, then run the console-type-specific tail.  The function
 * takes no arguments: its first call, func_020726D0 (sound init), is
 * `void (void)` and reads neither r0 nor r1, so the r0/r1 the caller
 * GFL_USE_InitGameSystems leaves behind are dead
 * (docs/idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_InitSound.c \
 *       --func GFL_USE_InitSound --addr 0x02005B24 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char _SndHeapBuf[];
extern char _SndState[];
extern char _SndArcPath[];
extern char _SndArc[];

extern void func_020726D0(void);
extern u32  NNS_SndHeapCreate(u32 off, u32 size);
extern void NNS_SndArcInit(char *a, char *b, u32 c, u32 d);
extern void GFL_USE_ResetSound(int a0);
extern int  OS_IsRunOnTwl(void);
extern void func_02005B6C(void);

void GFL_USE_InitSound(void)
{
    u32 handle;

    func_020726D0();
    handle = NNS_SndHeapCreate((u32)_SndHeapBuf, 0x95AD0);
    *(u32 *)(_SndState + 0x10) = handle;
    NNS_SndArcInit(_SndArc, _SndArcPath, handle, 0);
    GFL_USE_ResetSound(1);
    if (OS_IsRunOnTwl() == 1) {
        func_02005B6C();
    }
}
