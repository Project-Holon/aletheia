/*
 * function: func_021FCD0C
 * address: 0x021FCD0C
 * packet: pkt_ov186_021FCD0C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCDA0 0x021FCDA0 thumb ov186
 *   func_021FCEDC 0x021FCEDC thumb ov186
 *   func_021FCE60 0x021FCE60 thumb ov186
 *   func_02006254 0x02006254 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
extern int func_021FCDA0(char *),func_021FCEDC(char *),func_02006254(int);
struct Obj;
extern void func_021FCE60(char *,int),func_020061E4(int),func_0204B3DC(struct Obj *,unsigned int);
void func_021FCD0C(char *p)
{
    if(func_021FCDA0(p)) {
        *(signed char *)(p+0x4C)=func_021FCEDC(p);
        if(*(signed char *)(p+0x4C)) {
            if(((int (*)(char *,int))*(int *)(p+0x50))(p,*(signed char *)(p+0x4C))) {
                if(func_02006254(0x6FE)==0) func_020061E4(0x6FE);
                func_021FCE60(p,*(unsigned short *)(p+0x42));
            }
            if(*(unsigned char *)(p+0x4D)) {
                if(*(unsigned short *)(p+0x42)==0) func_0204B3DC((struct Obj *)*(int *)(p+0x28),0);
                else func_0204B3DC((struct Obj *)*(int *)(p+0x28),1);
                if(*(unsigned *)(p+4)==*(unsigned short *)(p+0x42)+*(unsigned short *)(p+0x44)) func_0204B3DC((struct Obj *)*(int *)(p+0x2C),0);
                else func_0204B3DC((struct Obj *)*(int *)(p+0x2C),1);
            }
        }
    }
    ((void (*)(char *))*(int *)(p+0x58))(p);
}
