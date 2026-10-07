/*
 * file:     btl_calc_p10.c
 * unit:     yes
 * function: func_021D775C, func_021D778C
 * address:  0x021D775C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021F3ECC     0x021F3ECC  data
 */
#include "../../matched/include/G_Tbl.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
} Tbl_021D775C;

typedef struct { unsigned int count; unsigned short keys[0x60]; int vals[0x60]; int a[0x60]; int b[0x60]; unsigned char c[0x60]; } Tbl_021D778C;

int func_021D775C(int key);
int func_021D778C(int key, int *out);
extern Tbl_021D775C g_021F3ECC;


int func_021D775C(int key)
{
    Tbl_021D775C *p = &g_021F3ECC;
    u32 i;

    i = p->count;
    if (i < 0x60) {
        for (;;) {
            if (p->keys[i] == key)
                return p->vals[i];
            if (p->keys[i] == 0)
                break;
            if (++i >= 0x60)
                break;
        }
    }
    return 0;
}

int func_021D778C(int key, int *out) { Tbl_021D778C *p=((Tbl_021D778C *)&g_021F3ECC); unsigned int i; for(i=p->count; i<0x60; i++) { if(key==p->keys[i]) { *out=p->vals[i]; return 1; } if(p->keys[i]==0) break; } return 0; }
