#include "stdafx.h"
#include "DirectInput.h"

int main()
{
    HRESULT hr = S_OK;

    (void)getchar();
    for (;;)
    {
        auto vSendCount = 0;
        
        INPUT vInputs[2]{};

        vInputs[0].type         = INPUT_KEYBOARD;
        vInputs[0].ki.wVk       = VK_LWIN;
        vInputs[0].ki.dwFlags   = 0;

        vInputs[1].type         = INPUT_KEYBOARD;
        vInputs[1].ki.wVk       = VK_TAB;
        vInputs[1].ki.dwFlags   = 0;

        vSendCount = DirectInput::SendInput(_countof(vInputs), vInputs, sizeof(vInputs[0]));

        Sleep(3000);

        vInputs[0].type         = INPUT_KEYBOARD;
        vInputs[0].ki.wVk       = VK_TAB;
        vInputs[0].ki.dwFlags   = KEYEVENTF_KEYUP;

        vInputs[1].type         = INPUT_KEYBOARD;
        vInputs[1].ki.wVk       = VK_LWIN;
        vInputs[1].ki.dwFlags   = KEYEVENTF_KEYUP;

        vSendCount = DirectInput::SendInput(_countof(vInputs), vInputs, sizeof(vInputs[0]));

        break;
    }

    return hr;
}
