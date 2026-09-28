/*
 * function: CTRDGi_IsTaskBusy
 * address:  0x021B86CA
 * packet:   pkt_ov093_021B86CA
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * CTRDGi_IsTaskBusy (libctrdg/ctrdg_task.o): nonzero return on the busy flag.
 * Read as a boolean; the u8 load is normalised through cmp/movs.
 */

typedef struct {
    void *task;
    void *callback;
    unsigned long result;
    unsigned char *data;
    unsigned char *adr;
    unsigned long offset;
    unsigned long size;
    unsigned char *dst;
    unsigned short sec_num;
    unsigned char busy;
    unsigned char param[1];
} CTRDGTaskInfo;

int CTRDGi_IsTaskBusy(CTRDGTaskInfo *pt)
{
    return pt->busy != 0;
}
