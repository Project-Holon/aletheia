/*
 * function: func_021DBBAC
 * address: 0x021DBBAC
 * packet: pkt_ov175_021DBBAC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F028 0x0203F028 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021E2F38 0x021E2F38 data a1
 */
struct Field {const char *name;unsigned long type;void *value;unsigned long size;};
extern int func_0203F028(const char *,const char *);
extern void func_02082D44(const void *,void *,unsigned long);
extern const char d_021E2F38[];
void func_021DBBAC(int count,struct Field **recs,void *dst,int nfields)
{
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(func_0203F028(f->name,d_021E2F38)==0)
                func_02082D44(f->value,dst,f->size);
        }
    }
}
