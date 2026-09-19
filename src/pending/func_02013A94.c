/*
 * function: func_02013A94
 * address:  0x02013A94
 * packet:   pkt_02013A94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0034 ABS32 sub_020A72A8_Key       : 020A72A8 (data, from header) has no witness outside 02013A94..02013AD0 +0038 ABS32 sub_020A72AA_Val       : 020A72AA (data, from header) has no witness outside 02013A94..02013AD0
 * symbols:
 *   sub_020A72A8_Key  0x020A72A8  data
 *   sub_020A72AA_Val  0x020A72AA  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sub_020A72A8_Key[];
extern u16 sub_020A72AA_Val[];

u16 func_02013A94(u32 key)
{
    int i;
    char *p = *(char **)0x02146264;

    for (i = 0; i < 2; i++) {
        if (*(u8 *)(p + 0x48 + i) != 0 && key == sub_020A72A8_Key[i * 2])
            return sub_020A72AA_Val[i * 2];
    }
}
