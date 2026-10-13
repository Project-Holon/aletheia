/*
 * function: DWCi_MOVStartAdmitChild
 * address:  0x021D3D44
 * packet:   pkt_021D3D44
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOVStartAdmitChild 0x021D3D44 arm
 *   DWCi_MOV_WH_Initialize  0x021D3638  arm
 *
 * Only from the three live modes, tear the sound system down and park it at mode 2.
 * Addresses are Black-image addresses.
 */

extern void func_021D3CD0(void);
extern int DWCi_MOV_WH_Initialize(void);

int DWCi_MOVStartAdmitChild(void)
{
    unsigned char mode = *(unsigned char *)(*(int *)0x021DE668 + 0xa90);

    if (mode != 1 && mode != 0x1a && mode != 0x1d)
        return 0;
    func_021D3CD0();
    DWCi_MOV_WH_Initialize();
    *(unsigned char *)(*(int *)0x021DE668 + 0xa90) = 2;
    return 1;
}

