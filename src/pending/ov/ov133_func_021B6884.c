/*
 * function: func_021B6884
 * address: 0x021B6884
 * packet: pkt_ov133_021B6884
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0204F32C and 0204F2FC have no outside witness; no overlay leaves filed.
 *   0204F32C verified EXACT by concurrent ov112_func_021F4DE0.c blocker (copy retained):
 *   typedef unsigned int u32;
 *   void func_0204F32C(char *p,u32 i,u32 *out) { *out = *(u32 *)(*(char **)(p+4)+i*40+36); }
 *   0204F2FC scratch one EXACT, 48 bytes, no relocations:
 *   typedef unsigned char u8;
 *   void func_0204F2FC(u8 *p,u32 i,u32 value) {
 *       u32 off = i*40;
 *       *(u32 *)(*(u8 **)(p+4)+off+32) = value;
 *       *(u32 *)(*(u8 **)(p+4)+off+12) = (*(u32 *)(*(u8 **)(p+4)+off+32)<<16)>>13;
 *   }
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA214 0x021BA214 thumb ov133
 *   func_021BA1EC 0x021BA1EC thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021B7A18 0x021B7A18 thumb ov133
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_021F4D74 0x021F4D74 thumb ov112
 *   func_021F4AA4 0x021F4AA4 thumb ov112
 *   func_0204F32C 0x0204F32C arm
 *   func_0204F2E4 0x0204F2E4 arm
 *   func_0204F2FC 0x0204F2FC arm
 *   func_0204EDD0 0x0204EDD0 arm
 *   func_0204F044 0x0204F044 arm
 *   func_0204F1A0 0x0204F1A0 arm
 *   func_0204A648 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021BA184(void *);
extern u8 *func_021BA218(u8 *);
extern u8 *func_021BA20C(u8 *);
extern u8 *func_021BA214(u8 *);
extern void func_021BA1EC(u8 *, void *, u8 *);
extern u8 *func_021BA208(u8 *);
extern void func_021B7A18(u8 *);
extern u32 func_021F4F10(u8 *);
extern u8 *func_021F4F54(u8 *, int);
extern int func_021F4F70(int *);
extern void func_021F4D74(u8 *, u8 *, int, u16);
extern void func_021F4AA4(void *);
extern void func_0204F32C(void *, int, u32 *);
extern void func_0204F2E4(u8 *, int, u32 *);
extern void func_0204F2FC(void *, int, u32);
extern void func_0204EDD0(int, u16 *, u16 *);
extern int func_0204F044(void *, int, int, int, u32, u8, u8);
extern void func_0204F1A0(void *, u32);
extern void func_0204A648(void);
void func_021B6884(void *unused, u8 *p)
{
    u32 height, width;
    u16 sizes[2];
    int changed;
    u8 *e, *q, *r;
    u8 *table;
    int flags;
    u16 index;
    e = func_021BA184(*(void **)(p + 0x181c));
    changed = 0;
    while (e) {
        func_021BA218(e);
        q = func_021BA20C(e);
        r = func_021BA214(e);
        if (*(u16 *)q != *(u16 *)r) {
            func_021BA1EC(e, *(void **)(p + 0x1884), r);
            changed = 1;
        }
        e = func_021BA208(e);
    }
    if (changed == 1) func_021B7A18(p);
    if (*(u8 **)(p + 0x38)) {
        q = func_021BA20C(*(u8 **)(p + 0x38));
        if (*(u16 *)(p + 0x50) != *(u16 *)q) {
            table = (u8 *)func_021F4F10(*(u8 **)(p + 0x1884));
            *(u16 *)(p + 0x50) = *(u16 *)q;
            func_0204F32C(*(void **)(p + 0x188c), *(int *)(p + 0x54), &height);
            func_0204F2E4(*(u8 **)(p + 0x188c), *(int *)(q + 4), &width);
            func_0204F2FC(*(void **)(p + 0x188c), *(int *)(p + 0x54), width);
            flags = func_021F4F70((int *)func_021F4F54(table, *(u16 *)(p + 0x50)));
            func_0204EDD0(flags, &sizes[1], &sizes[0]);
            index = func_0204F044(*(void **)(p + 0x188c), width, height, 0, flags, sizes[1], sizes[0]);
            func_021F4D74(*(u8 **)(p + 0x1884), *(u8 **)(p + 0x4c), *(u16 *)(p + 0x50), index);
            func_0204F1A0(*(void **)(p + 0x188c), *(u32 *)(p + 0x54));
            *(u32 *)(p + 0x54) = index;
        }
    }
    func_0204A648();
    func_021F4AA4(*(void **)(p + 0x1884));
}
