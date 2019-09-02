firebase::Future<firebase::auth::User*> result =
    auth->SignInWithCredentialLastResult();
if (result.status() == firebase::kFutureStatusComplete) {
  if (result.error() == firebase::auth::kAuthErrorNone) {
    firebase::auth::User* user = *result.result();
    printf("Sign in succeeded for `%s`\n", user->display_name().c_str());
  } else {
    printf("Sign in failed with error '%s'\n", result.error_message());
  }
}
