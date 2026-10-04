/*
 * function: func_021E1850
 * address: 0x021E1850
 * packet: pkt_ov183_021E1850
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj00732.h"
typedef unsigned short u16;
typedef struct {int tag,value,mode,handle; char rest[12];} Record;
extern int func_021E0E40(int,int);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021E1850(const Record *records)
{
    char *p=(char *)records;
    int i,old,value,offset;
    ((struct Obj00732 *)p)->f1DC=1;
    p[0x1f4]=0;
    if (((struct Obj00732 *)p)->f240==0) {
        i=((struct Obj00732 *)p)->f23C-1;
        ((struct Obj00732 *)p)->f188=i;
        value=records[i].value;
        ((struct Obj00732 *)p)->f318=1;
        ((struct Obj00732 *)p)->f31C=value;
        ((struct Obj00732 *)p)->f320=1;
    } else {
        i=((struct Obj00732 *)p)->f188;
        func_0204B878((struct Obj *)records[i].handle,func_021E0E40(((Record *)records)[i].tag=0,records[i].mode));
        old=records[i].value;
        if (i>0) {
            func_0204B878((struct Obj *)records[i-1].handle,func_021E0E40(records[i-1].tag,records[i-1].mode));
            value=records[i-1].value;
            if (old!=value) {
                ((struct Obj00732 *)p)->f318=1;
                ((struct Obj00732 *)p)->f31C=value;
                ((struct Obj00732 *)p)->f320=1;
            } else {
                ((struct Obj00732 *)p)->f318=2;
                ((struct Obj00732 *)p)->f31C=i-1;
            }
        } else ((struct Obj00732 *)p)->f350=1;
    }
}
