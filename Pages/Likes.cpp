void Likes(){
  Like* p = DB.Likes[s.Select("Gonderi", 
    DB.Likes.MapSelection(_(Like, x->user->username.append(" - ").append(x->post->text))))];
  if(!p) {
    cout << "Gonderi Yok" << endl;
    s.Wait();
    return;
  };
  s.Clear();
  cout << endl << 
    endl << "Beğenen: " << p->user->username <<
    endl << "Yazı:" << p->post->text << endl;
  s.Wait();
}