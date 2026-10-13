/*
 * function: func_021F26E0
 * address:  0x021F26E0
 * packet:   pkt_ov029_021F26E0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wave D5 lane 02): arm9 func_02035010/func_02035040 and their setters func_02035004/func_02035034 are now filed in src/matched/arm9/; remaining unresolved sites should clear once labelled.
 * 2026-10-04 (wD2 lane 09): bytes are identical; only +002A and +0032 are open:
 * calls to unlabelled arm9 02035010 and 02035040 (no witness).
 * A separate arm9 label lane must label them; nothing left in this source.
 *
 * Blocked: func_02035010 and func_02035040 (arm, unlabelled arm9 leaves, EL_GetGlobalAdr
 * wrappers per sdk_class.json) have no witness outside this range; both are the integrator's.
 * Byte-correct otherwise.
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Open: unlabelled arm9 02035010 and 02035040.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_021585E0  0x021585E0  thumb
 *   func_02158614  0x02158614  thumb
 *   func_021F2E5C  0x021F2E5C  thumb  ov029
 *   func_02035010  0x02035010  arm
 *   func_02035040  0x02035040  arm
 *   func_0203D8AC  0x0203D8AC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_02049238  0x02049238  arm
 *   func_021F1F24  0x021F1F24  thumb  ov029
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Node;
struct PalAnmSlot;
struct SoundSys;
extern u32 func_02012138(const struct Ctx *p);
extern int func_021585E0(int r);
extern void func_02158614(int a);
extern void func_021F2E5C(char *a);
extern void func_02035010(u32 a, u32 b);
extern void func_02035040(u32 a, u32 b);
extern void func_0203D8AC(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030DA4(int a);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern void func_02049238(int a);
extern void func_021F1F24(char *p);
extern void func_02082BCC(char *p, int a, int b);

void func_021F26E0(char *p)
{
    int r = func_02012138((const struct Ctx *)(*(int *)(p + 0x1c)));

    if (r != 0) {
        if (func_021585E0(r) == 2)
            func_02158614(r);
    }
    func_021F2E5C(p + 0x21c);
    func_02035010(0, 0);
    func_02035040(0, 0);
    func_0203D8AC();
    func_0203D34C(0, *(unsigned short *)(p + 0xc));
    func_020215A0((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3);
    func_020215A0((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1);
    func_02021540((void *)(*(int *)(p + 0x210)));
    func_02030DA4(*(int *)(p + 0x204));
    func_020307B0((void *)(*(int *)(p + 0x20c)));
    func_02030EAC((struct Node *)(*(int *)(p + 0x208)));
    if (*(int *)(p + 0x218) != 5) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4((const struct Ctx *)(*(int *)(p + 0x1c)))));
    }
    func_02049238(*(int *)(p + 0x24));
    func_021F1F24(p);
    *(volatile unsigned short *)0x04001050 = 0;
    func_02082BCC(p, 0, 0x468);
}
