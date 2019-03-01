#include "main.h"
#include "UserFrame.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    UserFrame *userFrame = new UserFrame(NULL);
    userFrame->Show(true);

    return true;
}
