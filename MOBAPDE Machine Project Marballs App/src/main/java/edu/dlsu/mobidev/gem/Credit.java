package edu.dlsu.mobidev.gem;

/**
 * Created by user on 12/15/2017.
 */

public class Credit {

    private String title;
    private String content;

    public Credit(String title, String content) {
        this.title = title;
        this.setContent(content);
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
