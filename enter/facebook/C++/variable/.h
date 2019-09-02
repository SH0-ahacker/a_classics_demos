firebase::auth::User* user = auth->current_user();
if (user != nullptr) {
  std::string name = user->display_name();
  std::string email = user->email();
  std::string photo_url = user->photo_url();
  // The user's ID, unique to the Firebase project.
  // Do NOT use this value to authenticate with your backend server,
  // if you have one. Use firebase::auth::User::Token() instead.
  std::string uid = user->uid();
}
