/*
 * function: func_02206710
 * address:  0x02206710
 * packet:   pkt_ov094_02206710
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm  arm9
 */

typedef struct { char pad[0x68]; unsigned int f68; } W;
extern W **TCBL_GetTaskUserData(void *h);

void func_02206710(void *h)
{
    (*TCBL_GetTaskUserData(h))->f68 &= 0x7fffffff;
}
