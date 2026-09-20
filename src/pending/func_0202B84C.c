/*
 * function: func_0202B84C
 * address:  0x0202B84C
 * packet:   pkt_0202B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * Blocked: three sites - the call to func_0202B818 and the two data
 * pointers Data_0209FF88 / Data_0209FF8C, each named only by this
 * function's own pool.  Closes when func_0202B818 is filed and the two
 * tables acquire a second reference.
 * symbols:
 *   Data_0209FF88  0x0209FF88  data
 *   Data_0209FF8C  0x0209FF8C  data
 *   func_0202B818  0x0202B818  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8   id;
    u8   pad[7];
    void (*fn)(void *);
} Entry;

extern const Entry Data_0209FF88[];
extern const Entry Data_0209FF8C[];
extern int func_0202B818(void);

void func_0202B84C(void *a)
{
    int v = func_0202B818();
    int i;

    for (i = 0; i < 9; i++) {
        if (v != Data_0209FF88[i].id && Data_0209FF88[i].fn != 0) {
            Data_0209FF88[i].fn(a);
        }
    }
    if (Data_0209FF8C[v].fn != 0) {
        Data_0209FF8C[v].fn(a);
    }
}
