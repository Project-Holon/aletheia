/*
 * function: WIH_StateInStartParent
 * address:  0x021781BC
 * packet:   pkt_ov014_021781BC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork     0x021797A8  data  ov014  a4
 *   WM_StartParent  0x0208F644  arm
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_StateOutStartParent  0x02178204  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *gWihWork;
int WM_StartParent(void *fn);
void WIH_SetError(int err);
void WIH_StateOutStartParent(u8 *obj);

int WIH_StateInStartParent(void)
{
    int r;

    if ((u32)(*(int *)(gWihWork + 0x1E70) - 4) <= 1)
        return 1;
    r = WM_StartParent(WIH_StateOutStartParent);
    if (r != 2) {
        WIH_SetError(r);
        return 0;
    }
    *(u16 *)(gWihWork + 0x1EA8) = 0;
    *(u16 *)(gWihWork + 0x1EAA) = 1;
    return 1;
}
