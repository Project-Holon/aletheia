typedef struct {
    int headerLen;
} Res;

extern int func_021BAFA0(Res *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p);
extern int func_021BB12C(Res *res_p, int pos, int len, char *token, int ic);
extern int func_021BB0BC(Res *res_p, int pos, int limit);

int func_021BBBC8(Res *res_p, char *label_p, int *pos_p)
{
    int linetop;
    int nextlinetop;
    int labelend;
    int valuetop;
    int valueend;
    int return_code_size;

    return_code_size = 0;
    linetop = func_021BAFA0(res_p, 12, res_p->headerLen, &labelend, &return_code_size);
    while (linetop > 0) {
        valueend = 0;
        nextlinetop = func_021BAFA0(res_p, linetop, res_p->headerLen, &labelend, &return_code_size);
        if (labelend > 0 && func_021BB12C(res_p, linetop, labelend, label_p, 0) == 0) {
            if (labelend + 1 < res_p->headerLen) {
                valueend = func_021BAFA0(res_p, labelend + 1, res_p->headerLen, 0, &return_code_size);
                if (valueend <= 0) {
                    valueend = res_p->headerLen;
                } else {
                    if (valueend < return_code_size) {
                        return -1;
                    }
                    valueend = valueend - return_code_size;
                }
                valuetop = func_021BB0BC(res_p, labelend + 1, valueend);
                if (valuetop < 0) {
                    valuetop = valueend;
                }
                *pos_p = valuetop;
                return valueend - valuetop;
            }
            return valueend;
        }
        linetop = nextlinetop;
    }
    return -1;
}
