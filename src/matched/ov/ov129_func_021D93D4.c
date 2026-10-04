/*
 * function: func_021D93D4
 * address: 0x021D93D4
 * packet: pkt_ov129_021D93D4
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DA158 0x021DA158 thumb ov129
 *   func_0204B878 0x0204B878 arm
 * Lever: subscript each record field; clear_record binds the element before its store.
 */

extern int func_021DA158(int x, int flag);
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
typedef struct  {
    int state, value, flag, handle;
    char tail[12];
}
Record;
static inline unsigned clear_record(Record *q)  {
    q->state=0;
    return func_021DA158(0,q->flag);
}
void func_021D93D4(const Record *p)  {
    int i, v, next;
    *(int *)((char *)p+0x1dc)=1;
    *(unsigned char *)((char *)p+0x1f4)=0;
    if(*(int *)((char *)p+0x240)==0)  {
        i=*(int *)((char *)p+0x23c)-1;
        *(int *)((char *)p+0x188)=i;
        next=p[i].value;
        *(int *)((char *)p+0x31c)=1;
        *(int *)((char *)p+0x320)=next;
        *(int *)((char *)p+0x324)=1;
        return;
    }
    i=*(int *)((char *)p+0x188);
    func_0204B878((struct Obj *)p[i].handle,clear_record(&((Record *)p)[i]));
    v=p[i].value;
    if(i>0)  {
        func_0204B878((struct Obj *)p[i-1].handle,func_021DA158(p[i-1].state,p[i-1].flag));
        next=p[i-1].value;
        if(v!=next)  {
            *(int *)((char *)p+0x31c)=1;
            *(int *)((char *)p+0x320)=next;
            *(int *)((char *)p+0x324)=1;
            return;
        }
        *(int *)((char *)p+0x31c)=2;
        *(int *)((char *)p+0x320)=i-1;
    }
}
