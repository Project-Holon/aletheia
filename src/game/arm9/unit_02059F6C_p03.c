/*
 * file:     unit_02059F6C_p03.c
 * unit:     yes
 * function: func_0205A10C, func_0205A11C
 * address:  0x0205A10C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   s_data_02146AAC  0x02146AAC  data
 *   cardi_param  0x02146AAC  data  a4
 */
typedef struct {
    int _r0;
    int len;
    int f2;
    int f3;
} CARDiParam;

void *func_0205A10C(void);
void CARDi_CommandBegin(int len);
extern void *s_data_02146AAC;


void *func_0205A10C(void)
{
    return s_data_02146AAC;
}


static CARDiParam cardi_param;


void CARDi_CommandBegin(int len)
{
    cardi_param.len = len;
}
