/*
 * function: func_021C5C00
 * address: 0x021C5C00
 * packet: pkt_ov136_021C5C00
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CC70 0x0202CC70 thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_021C6028 0x021C6028 thumb ov136
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_021C6028(u8 *p, u32 a1, int idx, int sel);
void func_021C5C00(u8 *p)
{
    u16 idx;
    u8 *row;
    u16 offset;
    u16 i;
    idx = 0;
    offset = 10 * *(u16 *)(p+28);
    row = *(u8 **)(p+8)+0x2e8+offset;
    offset += 2;
    for (i=0;i<10;i++) {
        if(row[i]==255) func_0202CC70(**(void ***)(p+8),idx);
        else {
            func_021C6028(p,idx,offset,row[i]);
            func_0202CC58(**(void ***)(p+8),idx);
        }
        offset++;
        idx++;
    }
}
