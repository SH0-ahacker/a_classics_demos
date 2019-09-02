void OnCreateCallback(const firebase::Future<firebase::auth::User*>& result,
                      void* user_data) {
  // The callback is called when the Future enters the `complete` state.
  assert(result.status() == firebase::kFutureStatusComplete);

  // Use `user_data` to pass-in program context, if you like.
  MyProgramContext* program_context = static_cast<MyProgramContext*>(user_data);

  // Important to handle both success and failure situations.
  if (result.error() == firebase::auth::kAuthErrorNone) {
    firebase::auth::User* user = *result.result();
    printf("Create user succeeded for email %s\n", user->email().c_str());

    // Perform other actions on User, if you like.
    firebase::auth::User::UserProfile profile;
    profile.display_name = program_context->display_name;
    user->UpdateUserProfile(profile);

  } else {
    printf("Created user failed with error '%s'\n", result.error_message());
  }
}

void CreateUser(firebase::auth::Auth* auth) {
  // Callbacks work the same for any firebase::Future.
  firebase::Future<firebase::auth::User*> result =
      auth->CreateUserWithEmailAndPasswordLastResult();

  // `&my_program_context` is passed verbatim to OnCreateCallback().
  result.OnCompletion(OnCreateCallback, &my_program_context);
}
