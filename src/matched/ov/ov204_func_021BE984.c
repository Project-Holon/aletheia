/*
 * function: func_021BE984
 * address: 0x021BE984
 * packet: pkt_ov204_021BE984
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned integer p+0xA8 at the first paired call, member address
 *   at the second, keeps equivalent addresses apart; pointer-only was 364
 *   bytes/275 different, this spelling EXACT380 (existing distinct-arithmetic idiom).
 * symbols:
 *   BG_SYS_DrawTileSub 0x020411E8 arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S { u8 pad[0xA8]; u8 data[4096]; };
extern void BG_SYS_DrawTileSub(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041B6C(u32);
int func_021BE984(struct S *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02040588(2,1);
        BG_SYS_DrawTileSub(2,0,8,64,2,(u32)p->data,0,8,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        BG_SYS_DrawTileSub(2,0,7,64,1,(u32)p+0xA8,0,7,64,32);
        BG_SYS_DrawTileSub(2,0,10,64,1,(u32)p->data,0,10,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        BG_SYS_DrawTileSub(2,0,6,64,1,(u32)p+0xA8,0,6,64,32);
        BG_SYS_DrawTileSub(2,0,11,64,1,(u32)p->data,0,11,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        BG_SYS_DrawTileSub(2,0,5,64,1,(u32)p+0xA8,0,5,64,32);
        BG_SYS_DrawTileSub(2,0,12,64,1,(u32)p->data,0,12,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        BG_SYS_DrawTileSub(2,0,4,64,1,(u32)p+0xA8,0,4,64,32);
        BG_SYS_DrawTileSub(2,0,13,64,1,(u32)p->data,0,13,64,32);
        func_02041B6C(2);
        *q=0;
        return 1;
    }
    return 0;
}
