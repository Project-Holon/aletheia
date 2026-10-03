/*
 * function: func_021B9FBC
 * address: 0x021B9FBC
 * packet: pkt_ov225_021B9FBC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA240 0x021BA240 thumb ov225
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021BA508 0x021BA508 thumb ov225
 *   d_021BBF2C 0x021BBF2C data a4
 */
typedef unsigned char u8;
typedef struct S S;
struct Entry {unsigned word[7];};
extern const struct Entry d_021BBF2C[];
extern void func_021BA240(char *);
extern void func_021B63D0(struct S *p);
extern int func_021B6470(u8 *);
extern int func_021B6448(u8 *);
extern void func_021BA508(char *);
void func_021B9FBC(char *p)
{
    *(int *)(p+0x24)=-1;*(int *)(p+0x28)=-1;func_021BA240(p);
    if(*(unsigned *)(p+0x20)==1) {*(unsigned *)(p+0x20)=0;return;}
    if(*(unsigned *)(p+0x20)==0 || *(unsigned *)(p+0x20)==2) {
        func_021B63D0(*(S **)(p+4));
        if(*(unsigned *)(p+0x20)==0) {
            int result=func_021B6470(*(u8 **)(p+4));
            if(result!=-1) {*(unsigned *)(p+0x20)=2;*(int *)(p+0x24)=result;}
        } else {
            int result=func_021B6448(*(u8 **)(p+4));
            if(result!=-1) {*(unsigned *)(p+0x20)=1;*(int *)(p+0x28)=result;}
        }
    }
    if(*(unsigned *)(p+0x20)==0 || *(unsigned *)(p+0x20)==3) {
        func_021BA508(p);
        if(*(unsigned *)(p+0x20)==0) {
            if(*(unsigned *)(p+0x44)==1) {*(unsigned *)(p+0x20)=3;*(unsigned *)(p+0x24)=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        } else {
            if(*(unsigned *)(p+0x44)==3) {*(unsigned *)(p+0x20)=1;*(unsigned *)(p+0x28)=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        }
    }
}
