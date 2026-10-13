/*
 * file:     dwc_account_1.c
 * unit:     yes
 * function: func_02059058, func_02059084
 * address:  0x02059058
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef struct {
    unsigned int id;
    unsigned int low;
} DWCstAccLoginId;

int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask);
unsigned long long DWCi_Acc_GetUserId(DWCstAccLoginId *userdata);

int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask)
{
    if (data & ~mask)
        return 0;
    *ptr = (*ptr & ~(mask << shift)) | (data << shift);
    return 1;
}


unsigned long long DWCi_Acc_GetUserId(DWCstAccLoginId *userdata)
{
    return ((unsigned long long)(userdata->id & 0x7ff) << 32) | userdata->low;
}
