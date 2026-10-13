/*
 * function: PMS_INPUT_MoveInitialCursor
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
 *   PMSI_SEARCH_GetKeyUp 0x021BB240 thumb ov110
 *   PMSI_SEARCH_GetKeyDown 0x021BB250 thumb ov110
 *   PMSI_SEARCH_GetKeyLeft 0x021BB260 thumb ov110
 *   PMSI_SEARCH_GetKeyRight 0x021BB270 thumb ov110
 *   PMSI_SEARCH_GetKeyKind 0x021BB280 thumb ov110
 */
#include "../include/Obj00296.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 PMSI_SEARCH_GetKeyUp(u32 i);
extern u8 PMSI_SEARCH_GetKeyDown(u32 i);
extern u8 PMSI_SEARCH_GetKeyLeft(u32 i);
extern int PMSI_SEARCH_GetKeyRight(int n);
extern u8 PMSI_SEARCH_GetKeyKind(u32 i);
int PMS_INPUT_MoveInitialCursor(u8 *p) {
    int x=((struct Obj00296 *)p)->f4C;
    int y;
    if(x!=254 && x!=252 && x!=253) {
        y=255;
        if(((struct Obj00296 *)p)->f38&64) y=PMSI_SEARCH_GetKeyUp(x);
        else if(((struct Obj00296 *)p)->f38&128) y=PMSI_SEARCH_GetKeyDown(x);
        else if(((struct Obj00296 *)p)->f38&16) y=PMSI_SEARCH_GetKeyRight(x);
        else if(((struct Obj00296 *)p)->f38&32) y=PMSI_SEARCH_GetKeyLeft(x);
        if(y!=255) { ((struct Obj00296 *)p)->f4E=((struct Obj00296 *)p)->f4C; ((struct Obj00296 *)p)->f4C=y; return 1; }
    } else if(((struct Obj00296 *)p)->f38&64) {
        if(((struct Obj00296 *)p)->f4E<=26) y=PMSI_SEARCH_GetKeyKind(((struct Obj00296 *)p)->f4E); else y=255;
        if(((struct Obj00296 *)p)->f4C==252) {
            if(y>=20 && y<=23) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=22; goto end64; }
        } else if(((struct Obj00296 *)p)->f4C==253) {
            if(y==24 || y==25 || y==16) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=25; goto end64; }
        } else {
            if(y==17 || y==18 || y==26) { ((struct Obj00296 *)p)->f4C=y; goto end64; }
            else { ((struct Obj00296 *)p)->f4C=26; goto end64; }
        }
end64: return 1;
    } else if(((struct Obj00296 *)p)->f38&128) {
        if(((struct Obj00296 *)p)->f4E<=26) y=PMSI_SEARCH_GetKeyKind(((struct Obj00296 *)p)->f4E); else y=255;
        if(((struct Obj00296 *)p)->f4C==252) {
            if(y>=0 && y<=3) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=2; goto end128; }
        } else if(((struct Obj00296 *)p)->f4C==253) {
            if(y>=4 && y<=6) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=5; goto end128; }
        } else {
            if(y>=7 && y<=9) { ((struct Obj00296 *)p)->f4C=y; goto end128; }
            else { ((struct Obj00296 *)p)->f4C=8; goto end128; }
        }
end128: return 1;
    } else if(((struct Obj00296 *)p)->f38&32) {
        switch(x) {
        case 254: ((struct Obj00296 *)p)->f4C=253; break;
        case 253: ((struct Obj00296 *)p)->f4C=252; break;
        case 252: ((struct Obj00296 *)p)->f4C=254; break;
        }
        return 1;
    } else if(((struct Obj00296 *)p)->f38&16) {
        switch(x) {
        case 254: ((struct Obj00296 *)p)->f4C=252; break;
        case 253: ((struct Obj00296 *)p)->f4C=254; break;
        case 252: ((struct Obj00296 *)p)->f4C=253; break;
        }
        return 1;
    }
    return 0;
}
