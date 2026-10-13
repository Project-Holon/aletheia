/*
 * function: DWCi_HLlLoadList
 * address:  0x021BD6EC
 * packet:   pkt_ov016_021BD6EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SETTIGNlGet             0x021CF404  arm
 *   DWCi_HLlLoad                 0x021BD674  arm
*/

typedef struct {
    unsigned char pad[0xF4];
    unsigned char idx;
} SETTINGINFO;

extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_HLlLoad(int idx);

void DWCi_HLlLoadList(void)
{
    DWCi_HLlLoad(DWCi_SETTIGNlGet()->idx + 2);
}
