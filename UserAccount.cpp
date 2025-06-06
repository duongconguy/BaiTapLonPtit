#include "UserAccount.h"
#include <sstream>
#include <vector>
#include <iomanip>

UserAccount::UserAccount() : role(UserRole::USER), isAutoGeneratedPassword(false), createdAt(0), lastLogin(0) {}

UserAccount::UserAccount(const std::string& username, const std::string& hashedPassword, const std::string& fullName, const std::string& email, const std::string& phone, UserRole role, bool isAutoGeneratedPassword, time_t createdAt, time_t lastLogin, const std::string& walletId)
    : username(username), hashedPassword(hashedPassword), fullName(fullName), email(email), phone(phone), role(role), isAutoGeneratedPassword(isAutoGeneratedPassword), createdAt(createdAt), lastLogin(lastLogin), walletId(walletId) {}

std::string UserAccount::serialize() const {
    std::ostringstream oss;
    oss << username << ',' << hashedPassword << ',' << fullName << ',' << email << ',' << phone << ','
        << static_cast<int>(role) << ',' << isAutoGeneratedPassword << ',' << createdAt << ',' << lastLogin << ',' << walletId;
    return oss.str();
}

UserAccount UserAccount::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(iss, token, ',')) tokens.push_back(token);
    if (tokens.size() < 10) return UserAccount();
    UserAccount acc;
    acc.username = tokens[0];
    acc.hashedPassword = tokens[1];
    acc.fullName = tokens[2];
    acc.email = tokens[3];
    acc.phone = tokens[4];
    acc.role = static_cast<UserRole>(std::stoi(tokens[5]));
    acc.isAutoGeneratedPassword = (tokens[6] == "1");
    acc.createdAt = std::stol(tokens[7]);
    acc.lastLogin = std::stol(tokens[8]);
    acc.walletId = tokens[9];
    return acc;
} 