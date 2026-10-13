/*
 * function: ISS_3DS_SYS_Delete
 * address:  0x0202B8E4
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tears the object down: ISS_3DS_SYS_FreeTable first, then the matched heap release
 * func_020307B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_3DS_SYS_Delete.c \
 *       --func ISS_3DS_SYS_Delete --addr 0x0202B8E4 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_3DS_SYS_FreeTable  0x0202B9C8  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern void ISS_3DS_SYS_FreeTable(struct Obj *o);
extern u32 func_020307B0(void *p);

void ISS_3DS_SYS_Delete(struct Obj *o)
{
    ISS_3DS_SYS_FreeTable(o);
    func_020307B0(o);
}
