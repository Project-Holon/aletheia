/*
 * function: VIEWER_TEXT_Delete
 * address:  0x021C7098
 * packet:   pkt_ov111_021C7098
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VIEWER_ACTOR_DeleteFont  0x021C795C  thumb
 *   VIEWER_ACTOR_DeleteBgWindow  0x021C78F8  thumb
 *   VIEWER_ACTOR_DeleteModel  0x021C7808  thumb
 *   VIEWER_ACTOR_Exit3D  0x021C7730  thumb
 *   VIEWER_ACTOR_DeleteObjects  0x021C7658  thumb
 *   VIEWER_TEXT_FreeBgResources  0x021C74D0  thumb
 *   VIEWER_TEXT_ExitBg  0x021C72C8  thumb
 *   VIEWER_TEXT_FreeResources  0x021C71CC  thumb
 *   VIEWER_ACTOR_SetRtcDate  0x021C81C0  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

extern void VIEWER_ACTOR_DeleteFont(Work *p);
extern void VIEWER_ACTOR_DeleteBgWindow(Work *p);
extern void VIEWER_ACTOR_DeleteModel(Work *p);
extern void VIEWER_ACTOR_Exit3D(Work *p);
extern void VIEWER_ACTOR_DeleteObjects(Work *p);
extern void VIEWER_TEXT_FreeBgResources(Work *p);
extern void VIEWER_TEXT_ExitBg(Work *p);
extern void VIEWER_TEXT_FreeResources(Work *p);
extern void VIEWER_ACTOR_SetRtcDate(Work *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void GFL_HEAP_DeleteChecked(u32 heap);

int VIEWER_TEXT_Delete(void *proc, void *seq, int c, Work *p)
{
    VIEWER_ACTOR_DeleteFont(p);
    VIEWER_ACTOR_DeleteBgWindow(p);
    VIEWER_ACTOR_DeleteModel(p);
    VIEWER_ACTOR_Exit3D(p);
    VIEWER_ACTOR_DeleteObjects(p);
    VIEWER_TEXT_FreeBgResources(p);
    VIEWER_TEXT_ExitBg(p);
    VIEWER_TEXT_FreeResources(p);
    VIEWER_ACTOR_SetRtcDate(p);
    func_020315D4(proc);
    func_0203084C(0x27);
    GFL_HEAP_DeleteChecked(0x27);
    return 1;
}
