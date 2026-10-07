/*
 * file:     unit_021B7658_p02.c
 * unit:     yes
 * function: func_021B7C90, func_021B7DA0
 * address:  0x021B7C90
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   func_020061E4 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_021B71C4 0x021B71C4 thumb ov173
 *   func_021B70D8 0x021B70D8 thumb ov173
 *   func_021B7F64 0x021B7F64 thumb ov173
 *   func_021B7FD0 0x021B7FD0 thumb ov173
 *   func_021B7ADC 0x021B7ADC thumb ov173
 */
#define S(p) (*(char **)(p))
struct Sound;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021B7EB0(char *,int);
extern u16 func_021B7438(char **);
extern void func_021B71C4(char *,int);
extern void func_020061E4(unsigned);
extern void func_021B70D8(char *);
extern void func_021B7F64(char *);
extern void func_021B7FD0(u8 *,int);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021B7ADC(unsigned char *p, u32 idx, int unused);
void func_021B7C90(char *p,int row,int old);
void func_021B7DA0(char *p,int i);

void func_021B7C90(char *p,int row,int old)
{
    
    func_021B7EB0(p,0);
    if(row<=3) {
        func_020061E4(0x54C);
        *(u16 *)(S(p)+0x14)=row;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) func_021B71C4(p,func_021B7438((char **)p));
        else func_021B71C4(p,-2);
    } else if(row==6) {
        if(old==3 && *(u16 *)(S(p)+0x16)+4<*(u8 *)(p+0x1B8)) {
            func_020061E4(0x54C);
            func_020260E4(*(void **)(p+0x1C8),row=3);
            (*(u16 *)(S(p)+0x16))++;
            func_021B70D8(p);
            func_021B71C4(p,func_021B7438((char **)p));
            func_021B7F64(p);
            func_021B7FD0((u8 *)p,1);
        } else if(old==0) {
            if(*(u16 *)(S(p)+0x16)!=0) {
                func_020061E4(0x54C);
                (*(u16 *)(S(p)+0x16))--;
                func_021B70D8(p);
                func_021B71C4(p,func_021B7438((char **)p));
                func_021B7F64(p);
                func_021B7FD0((u8 *)p,-1);
            }
            row=0;
            func_020260E4(*(void **)(p+0x1C8),0);
        } else {
            row=3;
            func_020260E4(*(void **)(p+0x1C8),3);
        }
    } else func_020061E4(0x54C);
    func_021B7ADC((u8 *)p,(u8)row,3);
}

/*
 *   one --thumb, no region: EXACT, 10 bytes, blocker260E4.log.
 *   void func_020260E4(unsigned char *p,unsigned value) {
 *       p[13]=value; p[14]=255; p[15]=255;
 *   }
 */
void func_021B7DA0(char *p,int i)
{
    if(i<=3) {
        *(u16 *)(S(p)+0x14)=i;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) {
            func_021B7EB0(p,1);
            func_021B71C4(p,func_021B7438((char **)p));
        } else {
            func_021B7EB0(p,0);
            func_021B71C4(p,-2);
        }
    } else if(i==4) {
        func_020061E4(0x54C);
        i=*(u16 *)(S(p)+0x14);
        (*(u16 *)(S(p)+0x16))++;
        func_021B71C4(p,func_021B7438((char **)p));
        func_021B70D8(p);
        func_021B7EB0(p,0);
        func_021B7F64(p);
        func_021B7FD0((u8 *)p,1);
        func_020260E4(*(void **)(p+0x1C8),i);
    } else if(i==5) {
        func_020061E4(0x54C);
        i=*(u16 *)(S(p)+0x14);
        (*(u16 *)(S(p)+0x16))--;
        func_021B71C4(p,func_021B7438((char **)p));
        func_021B70D8(p);
        func_021B7EB0(p,0);
        func_021B7F64(p);
        func_021B7FD0((u8 *)p,-1);
        func_020260E4(*(void **)(p+0x1C8),i);
    } else if(i==6) {
        if(*(u16 *)(p+0x1CC)!=6) {
            i=*(u16 *)(S(p)+0x14);
            func_020260E4(*(void **)(p+0x1C8),i);
        }
    } else if(i==7) {
        i=*(u16 *)(S(p)+0x14);
        func_020260E4(*(void **)(p+0x1C8),i);
    } else if(i==8) {
        if(*(u16 *)(p+0x1CC)!=6) {
            i=*(u16 *)(S(p)+0x14);
            func_020260E4(*(void **)(p+0x1C8),i);
        }
    }
    func_021B7ADC((u8 *)p,(u8)i,3);
}
