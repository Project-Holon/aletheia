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
typedef unsigned short u16;
typedef struct {int tag,value,mode,handle; char rest[12];} Record;
extern int func_021E0E40(int,int);
extern void func_0204B878(int,u16);
void func_021E1850(const Record *records)
{
    char *p=(char *)records;
    int i,old,value,offset;
    *(int *)(p+0x1dc)=1;
    p[0x1f4]=0;
    if (*(int *)(p+0x240)==0) {
        i=*(int *)(p+0x23c)-1;
        *(int *)(p+0x188)=i;
        value=records[i].value;
        *(int *)(p+0x318)=1;
        *(int *)(p+0x31c)=value;
        *(int *)(p+0x320)=1;
    } else {
        i=*(int *)(p+0x188);
        func_0204B878(records[i].handle,func_021E0E40(((Record *)records)[i].tag=0,records[i].mode));
        old=records[i].value;
        if (i>0) {
            func_0204B878(records[i-1].handle,func_021E0E40(records[i-1].tag,records[i-1].mode));
            value=records[i-1].value;
            if (old!=value) {
                *(int *)(p+0x318)=1;
                *(int *)(p+0x31c)=value;
                *(int *)(p+0x320)=1;
            } else {
                *(int *)(p+0x318)=2;
                *(int *)(p+0x31c)=i-1;
            }
        } else *(int *)(p+0x350)=1;
    }
}
