#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <map>

class Logger {

protected:

    /**
     * @brief Open a file at the given path and with the given name with .txt extension.
     * @param path
     * @param name
     */
    void open(const std::string &path, const std::string &name) {
        setPath(path);
        std::string temp = path + name + " " + datetime() + ".txt";
        map_ofstream[name] = new std::ofstream(temp.c_str(), std::ios::out);
    }

    /**
     * @brief Open a file at the specifed path set by setPath or in the current directory by default.
     * @param name
     */
    void open(const std::string &name) {
        open(path_, name);
    }

    /**
     * @brief Set the path of the directory where files will be stored.
     * @param path The path can be relative or absoulte abd should end with the / character.
     */
    void setPath(const std::string &path) {
        path_ = path;
    }

    /**
     * @brief Allows to access the first logger created by returning the ofstream.
     * @return
     */
    std::ofstream &write() {
        return *map_ofstream.begin()->second;
    }

    /**
     * @brief Allows to write data to the given logger. If the logger wasn't existing before it is created.
     * @param name
     * @return
     */
    std::ofstream &write(const std::string &name) {
        if (map_ofstream.find(name) == map_ofstream.end()) {
            open(path_, name);
        }
        return *map_ofstream[name];
    }

    /**
     * @brief Close all opened file and clear the map.
     */
    void close() {
        for (auto item : map_ofstream) {
            item.second->close();
        }
        map_ofstream.clear();
    }

    /**
     * @brief Gives the system date and time.
     * @return Return the system date and time in Day-Month-Year-Hours-Minutes-Seconds format.
     */
    static std::string datetime() {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "%d-%m-%Y-%H-%M-%S", timeinfo);
        return std::string(buffer);
    }

    /**
     * @brief Gives the system time.
     * @return Return the system time in Hours-Minutes-Seconds format.
     */
    static std::string timestamp() {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "%H-%M-%S", timeinfo);
        return std::string(buffer);
    }

    std::map<std::string, std::ofstream *> map_ofstream;
    std::string path_ = "./";
};

#endif // LOGGER_HPP
