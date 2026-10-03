/*
 * function: func_021BEC20
 * address: 0x021BEC20
 * packet: pkt_ov110_021BEC20
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: repeat the halfword store before a shared return label to retain the cross-jumped branch; descending switch bodies retain the tail layout.
 * abi: full getter bodies at 021BB240/250/260/270/280 read only r0 and return a zero-extended table byte.
 * symbols:
 *   func_021BB240 0x021BB240 thumb ov110
 *   func_021BB250 0x021BB250 thumb ov110
 *   func_021BB260 0x021BB260 thumb ov110
 *   func_021BB270 0x021BB270 thumb ov110
 *   func_021BB280 0x021BB280 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021BB240(u32 i);
extern u8 func_021BB250(u32 i);
extern u8 func_021BB260(u32 i);
extern int func_021BB270(u32);
extern u8 func_021BB280(u32 i);
int func_021BEC20(u8 *p) {
    int x=*(u16 *)(p+0x4c);
    int y;
    if(x!=254 && x!=252 && x!=253) {
        y=255;
        if(*(u16 *)(p+0x38)&64) y=func_021BB240(x);
        else if(*(u16 *)(p+0x38)&128) y=func_021BB250(x);
        else if(*(u16 *)(p+0x38)&16) y=func_021BB270(x);
        else if(*(u16 *)(p+0x38)&32) y=func_021BB260(x);
        if(y!=255) { *(u16 *)(p+0x4e)=*(u16 *)(p+0x4c); *(u16 *)(p+0x4c)=y; return 1; }
    } else if(*(u16 *)(p+0x38)&64) {
        if(*(u16 *)(p+0x4e)<=26) y=func_021BB280(*(u16 *)(p+0x4e)); else y=255;
        if(*(u16 *)(p+0x4c)==252) {
            if(y>=20 && y<=23) { *(u16 *)(p+0x4c)=y; goto end64; }
            else { *(u16 *)(p+0x4c)=22; goto end64; }
        } else if(*(u16 *)(p+0x4c)==253) {
            if(y==24 || y==25 || y==16) { *(u16 *)(p+0x4c)=y; goto end64; }
            else { *(u16 *)(p+0x4c)=25; goto end64; }
        } else {
            if(y==17 || y==18 || y==26) { *(u16 *)(p+0x4c)=y; goto end64; }
            else { *(u16 *)(p+0x4c)=26; goto end64; }
        }
end64: return 1;
    } else if(*(u16 *)(p+0x38)&128) {
        if(*(u16 *)(p+0x4e)<=26) y=func_021BB280(*(u16 *)(p+0x4e)); else y=255;
        if(*(u16 *)(p+0x4c)==252) {
            if(y>=0 && y<=3) { *(u16 *)(p+0x4c)=y; goto end128; }
            else { *(u16 *)(p+0x4c)=2; goto end128; }
        } else if(*(u16 *)(p+0x4c)==253) {
            if(y>=4 && y<=6) { *(u16 *)(p+0x4c)=y; goto end128; }
            else { *(u16 *)(p+0x4c)=5; goto end128; }
        } else {
            if(y>=7 && y<=9) { *(u16 *)(p+0x4c)=y; goto end128; }
            else { *(u16 *)(p+0x4c)=8; goto end128; }
        }
end128: return 1;
    } else if(*(u16 *)(p+0x38)&32) {
        switch(x) {
        case 254: *(u16 *)(p+0x4c)=253; break;
        case 253: *(u16 *)(p+0x4c)=252; break;
        case 252: *(u16 *)(p+0x4c)=254; break;
        }
        return 1;
    } else if(*(u16 *)(p+0x38)&16) {
        switch(x) {
        case 254: *(u16 *)(p+0x4c)=252; break;
        case 253: *(u16 *)(p+0x4c)=254; break;
        case 252: *(u16 *)(p+0x4c)=253; break;
        }
        return 1;
    }
    return 0;
}
