#include "iostream"
#include "functional"   //函数包装器头文件

void save_with_free_fun(const std::string &file_name)
{
    std::cout << "自由函数: " << file_name << std::endl;
}

class FileSave
{
public:
    void save_with_member_fun(const std::string &file_name)
    {
        std::cout << "成员函数: " << file_name << std::endl;
    }
};

int main()
{
    FileSave file_save; 
    auto save_with_lambda_fun = [](const std::string &file_name)
    {
        std::cout << "lambda函数: " << file_name << std::endl;
    };

    // save_with_free_fun("free_function.txt");
    // file_save.save_with_member_fun("member_function.txt");
    // save_with_lambda_fun("lambda_function.txt");

    std::function<void(const std::string&)> save1 = save_with_free_fun;
    std::function<void(const std::string&)> save2 = std::bind(&FileSave::save_with_member_fun, &file_save, std::placeholders::_1);
    std::function<void(const std::string&)> save3 = save_with_lambda_fun;

    save1("ndwq");
    save2("miownd");
    save3("jdowe");

    return 0;
}