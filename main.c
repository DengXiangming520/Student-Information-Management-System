/**********************************************************************************************************************
 *                                                    _ooOoo_                                                         *
 *                                                   o8888888o                                                        *
 *                                                   88" . "88                                                        *
 *                                                   (| -_- |)                                                        *
 *                                                    O\ = /O                                                         *
 *                                                 ___/`---'\____                                                     *
 *                                                .   ' \\| |// `.                                                    *
 *                                               / \\||| : |||// \                                                    *
 *                                             / _||||| -:- |||||- \                                                  *
 *                                             /  | | \\\ - /// | | \                                                 *
 *                                                 | \_| ''\---/'' | |                                                *
 *                                              \ .-\__ `-` ___/-. /                                                  *
 *                                            ___`. .' /--.--\ `. . __                                                *
 *                                         ."" '< `.___\_<|>_/___.' >'"".                                             *
 *                                       | | : `- \`.;`\ _ /`;.`/ - ` : | |                                           *
 *                                         \ \ `-. \_ __\ /__ _/ .-` / /                                              *
 *                                   ======`-.____`-.___\_____/___.-`____.-'======                                    *
 *                                                     `=---='                                                        *
 *                                                                                                                    *
 *                                   .............................................                                    *
 *                                            ????????             ????BUG                                              *
 **********************************************************************************************************************/


#include "heads/for_main.h"

int main() {
    //??????????
    main_menu();

    //??????????????????????????
    char main_menu_input;
    re_input_main_menu_choice:
    printf("-> ????????????1/2/3??");
    fflush(stdin);
    scanf("%c",&main_menu_input);
    switch (main_menu_input) {
        //????
        case '1':{
            login_module();
            break;
        }
        //????
        case '2':{
            registered_module();
            break;
        }
        //????
        case '3':{
            exit(0);
        }
        //??????????
        default:{
            printf("->????????????????????????\n\n");
            fflush(stdin);
            goto re_input_main_menu_choice;
        }
    }
    return 0;
}
