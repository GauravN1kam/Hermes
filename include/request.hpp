#include <string>
class Request{
    private:
        std::string full_path;
        std::string path;
        std::string req;
        std::string body;

    public:
        Request(std::string http);
        std::string getBody();
        std::string getPath();

};
