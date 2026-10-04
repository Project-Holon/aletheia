/*
 * function: func_02164D6C
 * address:  0x02164D6C
 * packet:   pkt_ov010_02164D6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame poll: state 1 finishes a request; otherwise, while the 9-byte
 * record at +0x74 is empty, picks an entry with func_02164E04 and copies it in.
 *
 * symbols:
 *   func_0203D0FC  0x0203D0FC  arm
 *   func_02164E04  0x02164E04  thumb ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203CF3C  0x0203CF3C  arm
 *   func_02026A60  0x02026A60  thumb
 *   func_02177BF4  0x02177BF4  thumb ov014
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    u8 b0;
    u8 lo : 4;
    u8 hi : 4;
    u8 flag : 1;
    u8 kind : 5;
    u8 rest : 2;
} Ent;

extern void  func_0203D0FC(int a);
extern Ent  *func_02164E04(u8 *obj, int *out);
extern void  func_02082BCC(void *dst, int v, int n);
extern void *func_0203CF3C(u32 a);
extern void  func_02026A60(void *a);
extern void func_02177BF4(unsigned int idx);

u8 *func_02164D6C(u8 *obj, int *arg)
{
    Ent *e;
    u8 *src;
    int i;
    u8 *rec = obj + 0x74;
    if (*(int *)(obj + 4) == 0) {
        return 0;
    }
    if (*(int *)(obj + 4) == 1) {
        func_0203D0FC(0);
        *(int *)(obj + 4) = 2;
        return 0;
    }
    if (rec[0] == 0) {
        e = func_02164E04(obj, arg);
        if (e != 0) {
            if (e->flag != 0) {
                func_02177BF4(*arg);
            } else if (e->kind == 1) {
                i = 0;
                func_02082BCC(rec, 0, 9);
                rec[0] = e->b0;
                rec[1] = e->lo;
                rec[2] = e->hi;
                src = func_0203CF3C((u32)*arg);
                for (i = 0; i < 6; i++) {
                    rec[3 + i] = src[i];
                }
            } else if (e->kind == 2) {
                func_02026A60((u8 *)e + 8);
                func_02177BF4(*arg);
            }
        }
    }
    if (rec[0] == 0) {
        rec = 0;
    }
    return rec;
}
