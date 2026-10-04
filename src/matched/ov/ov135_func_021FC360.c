/*
 * function: func_021FC360
 * address: 0x021FC360
 * packet: pkt_ov135_021FC360
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;
extern void func_02082BCC(void *, int, int);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B84C(void *, int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0203D34C(u32 a, u32 b);
void func_021FC360(char *p)
{
    ObjPos pos;
    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = 0xd0;
    pos.y = 0x3a;
    *(void **)(p + 0xd08) = func_0204B294(*(void **)(p + 0xbc0), (unsigned int)*(void **)(p + 0xbc4), (unsigned int)*(void **)(p + 0xbc8), (unsigned int)*(void **)(p + 0xbcc), &pos, 0, 0x48);
    func_0204B92C(*(void **)(p + 0xd08), 1);
    func_0204B878(*(void **)(p + 0xd08), 0x24);
    func_0204B84C(*(void **)(p + 0xd08), 1);
    func_0204B3DC(*(void **)(p + 0xd08), 1);
    func_0203D34C(0, 0x48);
}
