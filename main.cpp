#include<iostream>
#include"Subject.h"
#include"Engine.h"

int main() {
    Subject subj;
    Wrapper wrapper1(&subj, &Subject::func1, { {"arg1", 0} });
    Wrapper wrapper2(&subj, &Subject::func2, { {"arg1", 0}, {"arg2", 0} });
    Wrapper wrapper3(&subj, &Subject::func3, { {"arg1", 0}, {"arg2", 0}, {"arg3", 0} });

    Engine engine;
    engine.register_command(&wrapper1, "command1");
    engine.register_command(&wrapper2, "command2");
    engine.register_command(&wrapper3, "command3");

    std::cout << engine.execute("command1", { {"arg1", 4} }) << std::endl;
    std::cout << engine.execute("command2", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
    std::cout << engine.execute("command3", { {"arg1", 4}, {"arg2", 5}, {"arg3", 6} }) << std::endl;

    std::cout << engine.execute("command2", { {"arg2", 5}, {"arg1", 4} }) << std::endl;
    std::cout << engine.execute("command3", { {"arg1", 4}, {"arg2", 5}, {"abc", 6} }) << std::endl;
    std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;

    return 0;

}