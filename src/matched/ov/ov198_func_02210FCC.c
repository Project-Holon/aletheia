/*
 * function: B_PLIST_MAIN_InitSelectionForMode
 * address: 0x02210FCC
 * packet: pkt_ov198_02210FCC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_RecreateCursor 0x022119F8 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void B_PLIST_MAIN_RecreateCursor(u8 *,u32,u32);
void B_PLIST_MAIN_InitSelectionForMode(u8 *p, u32 state)
{
    u32 value;
    switch(state) {
    case 0: case 8:
        p[0x2190]=0;
        (*(u8 **)p)[0x4B]=0;
        value=(*(u8 **)p)[0x20];
        break;
    case 1:
        (*(u8 **)p)[0x4B]=0;
        value=p[0x2190];
        break;
    case 3: case 4:
        value=(*(u8 **)p)[0x4B];
        break;
    case 6: value=p[0x2191]; break;
    case 7: value=p[0x2192]; break;
    case 2: case 5: value=0; break;
    }
    B_PLIST_MAIN_RecreateCursor(p,state,value);
}
