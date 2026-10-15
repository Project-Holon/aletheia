/*
 * function: DWCi_Acc_GetFlag_DataType
 * address:  0x0205911C
 * packet:   pkt_0205911C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02059108    0x02059108  arm
*/

typedef struct {
    unsigned char pad[1];
} DWCstAccFlag;
extern unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata);

unsigned long DWCi_Acc_GetFlag_DataType(void *userdata)
{
    return DWCi_Acc_GetFlags(userdata) & 3;
}
