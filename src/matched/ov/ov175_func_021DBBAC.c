/*
 * function: WIFIBATTLEMATCH_NET_GdbCopyFieldE
 * address: 0x021DBBAC
 * packet: pkt_ov175_021DBBAC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_STANDARD_CompareString 0x0203F028 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   d_021E2F38 0x021E2F38 data a1
 */
struct Field {const char *name;unsigned long type;void *value;unsigned long size;};
extern int GF_STANDARD_CompareString(const char *,const char *);
extern void MI_CpuCopy8(const void *,void *,unsigned long);
extern const char d_021E2F38[];
void WIFIBATTLEMATCH_NET_GdbCopyFieldE(int count,struct Field **recs,void *dst,int nfields)
{
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(GF_STANDARD_CompareString(f->name,d_021E2F38)==0)
                MI_CpuCopy8(f->value,dst,f->size);
        }
    }
}
