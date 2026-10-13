/*
 * function: DWCi_MOV_WH_ChildConnectAuto
 * address:  0x02178524
 * packet:   pkt_ov014_02178524
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * b is const: that is what lets the ldrh of b[1] schedule above the strh of
 * b[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 *
 * symbols:
 *   gWihWork     0x021797A8  data   ov014  a4
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   DWCi_MOV_WH_StateInStartScan  0x0217863C  thumb  ov014
 *   MI_CpuFill8  0x02082BCC  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *gWihWork;
void WIH_ChangeSysState(int state);
void MI_CpuFill8(void *p, u32 v, u32 n);
int DWCi_MOV_WH_StateInStartScan(void);

int DWCi_MOV_WH_ChildConnectAuto(u32 a, const u16 *b, u32 c)
{
    WIH_ChangeSysState(2);
    if (b != 0) {
        *(u16 *)(gWihWork + 0x140E) = b[2];
        *(u16 *)(gWihWork + 0x140C) = b[1];
        *(u16 *)(gWihWork + 0x140A) = b[0];
    } else {
        MI_CpuFill8(gWihWork + 0x140A, 0xff, 6);
    }
    *(u32 *)(gWihWork + 0x1E74) = a;
    *(u32 *)(gWihWork + 0x1E94) = 0;
    *(u16 *)(gWihWork + 0x1EB2) = c;
    *(u16 *)(gWihWork + 0x1406) = 1;
    *(u16 *)(gWihWork + 0x1EB4) = 1;
    if (DWCi_MOV_WH_StateInStartScan() == 0) {
        WIH_ChangeSysState(9);
        return 0;
    }
    return 1;
}
