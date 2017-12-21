package edu.dlsu.mobidev.gem;

import android.content.Context;
import android.database.Cursor;
import android.provider.ContactsContract;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

/**
 * Created by user on 12/15/2017.
 */

public class HighScoreAdapter extends CursorRecyclerViewAdapter<HighScoreAdapter.HighScoreViewHolder> {
    public HighScoreAdapter(Context context, Cursor cursor) {
        super(context, cursor);
    }

    @Override
    public void onBindViewHolder(HighScoreViewHolder viewHolder, Cursor cursor) {
        // cursor is already pointed at the current position
        long id = cursor.getLong(cursor.getColumnIndex(HighScore.COLUMN_ID));
        String name = cursor.getString(cursor.getColumnIndex(HighScore.COLUMN_NAME));
        int highscore = cursor.getInt(cursor.getColumnIndex(HighScore.COLUMN_HIGHSCORE));
        String date = cursor.getString(cursor.getColumnIndex(HighScore.COLUMN_DATE));

        viewHolder.tvName.setText(name + "");
        viewHolder.tvHighScore.setText(highscore + "");
        viewHolder.tvDate.setText(date + "");

        // set the database id to the viewholder's itemView (the "whole row" view)
        viewHolder.itemView.setTag(id);
    }

    @Override
    public HighScoreViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.list_item_highscore, parent, false);
        return new HighScoreViewHolder(v);
    }

    public class HighScoreViewHolder extends RecyclerView.ViewHolder {
        TextView tvName;
        TextView tvHighScore;
        TextView tvDate;

        public HighScoreViewHolder(View itemView) {
            super(itemView);
            tvName = (TextView) itemView.findViewById(R.id.tvName);
            tvHighScore = (TextView) itemView.findViewById(R.id.tvHighscore);
            tvDate = (TextView) itemView.findViewById(R.id.tvDate);
        }
    }
}
