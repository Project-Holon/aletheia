/*
 * function: func_0202A084
 * address:  0x0202A084
 * packet:   pkt_0202A084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   tbl_0209FED4   0x0209FED4  data  a1
 *   func_02072788  0x02072788  arm
 *   func_0202A02C  0x0202A02C  thumb
 *   func_0202A01C  0x0202A01C  thumb
 *   func_02029FF8  0x02029FF8  thumb
 *
 * ringtone_sys.c: the ringtone state machine.  The next state is a byte of
 * the 4-column transition table at 0x0209FED4, tbl[state][event]; a plain
 * 2D subscript is the addressing the image has (base + state * 4, then
 * `ldrb [event, base]`), which the byte-offset spellings of
 * docs/notes/pkt_0202A084.c.txt never gave.  Case 1 and case 3 are written
 * out separately with the same body: the image's case 1 is a lone `b` into
 * case 3 (cross-jumped), not a shared label.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 tbl_0209FED4[][4];
extern void func_02072788(int vol);
extern int func_0202A02C(int a0, int a1);
extern int func_0202A01C(int a0);
typedef unsigned short u16;
extern void func_02029FF8(u16 *p);

void func_0202A084(u32 *p, int event)
{
    u8 v = tbl_0209FED4[*p][event];

    switch (v) {
    case 0:
        func_02072788(0x7f);
        func_0202A02C((int)p, 0);
        func_0202A01C((int)p);
        break;
    case 1:
        func_02072788(0x7f);
        func_0202A02C((int)p, 1);
        func_02029FF8((u16 *)p);
        break;
    case 2:
        func_02072788(0);
        func_0202A01C((int)p);
        break;
    case 3:
        func_02072788(0x7f);
        func_0202A02C((int)p, 1);
        func_02029FF8((u16 *)p);
        break;
    }
    *p = v;
}
