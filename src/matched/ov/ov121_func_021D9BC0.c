/*
 * function: func_021D9BC0
 * address: 0x021D9BC0
 * packet: pkt_ov121_021D9BC0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: const record pointer settles stack-store schedule;
 *       two trailing zero alignment bytes.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_021D9BE8 0x021D9BE8 thumb ov121
 */
typedef unsigned char u8;
typedef struct { int x; int y; } Pair;
extern void *func_02045770(void *);
extern void func_021D9BE8(unsigned,const Pair *,const void *,void *,int,Pair *);
void func_021D9BC0(const u8 *p,int a,Pair *out) {
    void *bitmap=func_02045770(*(void **)(p+0xc));
    func_021D9BE8(*(unsigned *)(p+0x20),(const Pair *)(p+0x18),bitmap,*(void **)(p+0x10),a,out);
}
