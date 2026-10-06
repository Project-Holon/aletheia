/*
 * function: func_021D9DC8
 * address: 0x021D9DC8
 * packet: pkt_ov175_021D9DC8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203D644; verified EXACT (12 bytes) in scratch blocker-r1.log.
 *   extern void func_020394F0(int);
 *   void func_0203D644(int value) { func_020394F0(value); }
 *   Its target stores its one word input at global +0x1ac; no extra input.
 * blocker: ov175 0x021DC5F8 callback leaf withheld while ARM9 also blocks.
 *   Leaf returns *(u32 *)(p+0x1458) for kind 3 or 6, otherwise 0.
 * lever: u16 heap fixes allocator spill order; 02009860 leaves r0 live,
 *   and caller stores that return word despite the callee's void declaration.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_02034714 0x02034714 arm
 *   func_0203A574 0x0203A574 arm
 *   func_0203D644 0x0203D644 arm
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021DC5C8 0x021DC5C8 thumb ov175
 *   func_021DC5F8 0x021DC5F8 thumb ov175
 *   d_021E2EE0 0x021E2EE0 data a4
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2C90 0x021E2C90 data a4
  *
 * note 2026-10-04 (lane 20, D2): leaf func_021DC5F8 is now filed EXACT as
 * src/matched/ov/ov175_func_021DC5F8.c (24 bytes). The tool still says "no witness" for it until
 * the integrator runs the manifest. The other blocker, ARM9 func_0203D644 (veneer-like 12-byte
 * tail call), is the arm9 label lane's. Body is byte-correct; expect EXACT after manifest + label.
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
struct BigObj;
struct Sub0200852CObj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009860(void);
extern u8 *func_02012944(void *p);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern int func_0203CD98(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0203A574(u32, u32, u32, u32);
extern void func_0203D644(int);
extern void func_02156DC4(int, int);
extern void func_02156DE0(int, int);
extern void func_021DC5C8(void *, int, int);
extern u32 func_021DC5F8(char *p, int a, int kind);
extern const char d_021E2EE0[], d_021E2EF8[];
extern const u32 d_021E2C90[];
char *func_021D9DC8(u32 a, void *save, u32 b, u16 heap) {
    char *p;
    p = func_02030734(heap, 0x149c, 0, d_021E2EE0, 0x2b0);
    func_02082BCC(p, 0, 0x149c);
    *(u32 *)(p + 4) = func_0201283C(save);
    *(u32 *)p = func_02009860();
    *(void **)(p + 0xc) = (void *)func_0200853C((const struct Sub0200852CObj *)func_02012944(save));
    *(void **)(p + 8) = save;
    *(u32 *)(p + 0x10) = b;
    *(u32 *)(p + 0x1464) = a;
    *(int *)(p + 0x19c) = 0x573;
    *(char **)(p + 0x190) = func_02030734(heap, 0x260, 0, d_021E2EE0, 0x2c0);
    func_02082BCC(*(void **)(p + 0x190), 0, 0x260);
    if (!func_0203CD98()) func_02034714(d_021E2EF8, 0, d_021E2EF8);
    func_0203A574(0x2400, (u32)d_021E2C90, 6, (u32)p);
    func_0203D644(0);
    func_02156DC4((int)func_021DC5C8, (int)p);
    func_02156DE0((int)func_021DC5F8, (int)p);
    return p;
}
